#pragma once

#include <string>

struct IDataBase {
    virtual void Write(const std::string& str) = 0;
    virtual std::string GetIp(size_t index) = 0;
};

struct TDataBase: public IDataBase {
    virtual void Write(const std::string& str) override;
    virtual std::string GetIp(size_t index) override;
};

class TDataStorage {
public:
    // a lot of params
    TDataStorage(IDataBase* db)
        : dbase(db){};

    std::string Do(const std::string& query) {
        dbase->Write(query);
        dbase->GetIp(query.size());
        // action
        return Name;
    }

private:
    IDataBase* dbase = nullptr;
    // a lot of data fields
    // ...
    std::string Name;
    // a lot of private methods
    // ...

    // std::string GetNormalizedName();
};

std::string GetNormalizedName(const std::string& Name);
