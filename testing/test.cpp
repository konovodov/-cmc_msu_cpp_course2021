#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "datastorage.h"

struct TDataBaseStub: public IDataBase {
    virtual void Write(const std::string& str) override {
        // nothing
        return;
    }
    virtual std::string GetIp(size_t index) override {
        return "";
    }
};

struct TDataBaseMock: public IDataBase {
    MOCK_METHOD1(Write, void(const std::string&));
    MOCK_METHOD1(GetIp, std::string(size_t));
};

TEST(MyTest, TestGetNormalizedName) {
    std::string name;
    EXPECT_EQ("ab cd e ", GetNormalizedName("ab  cd    e    "));
    EXPECT_EQ(" ", GetNormalizedName("        "));
    EXPECT_EQ(" a ", GetNormalizedName("      a   "));
}

TEST(MyTest, TestDataStorage) {
    TDataBaseStub dbs;
    TDataStorage storage(&dbs);
    EXPECT_EQ("", storage.Do("smth"));
}

TEST(MyTest, TestDataStorageWithMock) {
    TDataBaseMock dbm;
    TDataStorage storage(&dbm);
    EXPECT_CALL(dbm, Write("smth"));
    EXPECT_CALL(dbm, GetIp(::testing::_));
    storage.Do("smth");
}
