#include "datastorage.h"

std::string GetNormalizedName(const std::string& Name) {
    if (Name.size() <= 1)
        return Name;
    std::string result;
    for (size_t i = 0; i < Name.size(); ++i) {
        if (std::isspace(Name[i]) && std::isspace(Name[i - 1])) {
            continue;
        }
        result.push_back(Name[i]);
    }
    return result;
}
