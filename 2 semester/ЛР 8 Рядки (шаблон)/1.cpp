#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    string valuesStr, templateStr;
    getline(cin, valuesStr);
    getline(cin, templateStr);

    unordered_map<string, string> valuesMap;
    size_t pos = 0;
    while (pos < valuesStr.length()) {
        
        size_t equalPos = valuesStr.find('=', pos);
        if (equalPos == string::npos)
            break;
        
        string name = valuesStr.substr(pos, equalPos - pos);
        size_t commaPos = valuesStr.find(',', equalPos);
        string value = valuesStr.substr(equalPos + 1, commaPos - equalPos - 1);
        
        valuesMap[name] = value;
        
        if (commaPos == string::npos)
            break;
        pos = commaPos + 1;
    }

   
    for (const auto& pair : valuesMap) {
      
        string placeholder = "[" + pair.first + "]";
     
        size_t pos = templateStr.find(placeholder);
        while (pos != string::npos) {
            templateStr.replace(pos, placeholder.length(), pair.second);
            pos = templateStr.find(placeholder, pos + pair.second.length());
        }
    }

  
    cout << templateStr << std::endl;

    return 0;
}