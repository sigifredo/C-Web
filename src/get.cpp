

#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>

#define QUERY_MAX_SIZE          1024

typedef std::map<std::string, std::string> Map;

Map getData();

int main ()
{
    std::cout << "Content-type:text/html\r\n\r\n";
    Map data = getData();

    std::cout << "<!DOCTYPE html>" << std::endl;
    std::cout << "<html>" << std::endl;
    std::cout << "<head>" << std::endl;
    std::cout << "<title>GET request</title>" << std::endl;
    std::cout << "</head>" << std::endl;
    std::cout << "<body>" << std::endl;
    std::cout << "<table border=\"1\">" << std::endl;
    std::cout << "<tr><th>Variable</th><th>Valor</th></tr>" << std::endl;

    for (auto& var: data)
        std::cout << "<tr><td>" << var.first << "</td><td>" << var.second << "</td></tr>" << std::endl;

    std::cout << "</table>" << std::endl;
    std::cout << "</body>" << std::endl;
    std::cout << "</html>" << std::endl;

    return 0;
}

Map getData()
{
    Map data;
    std::istringstream raw(std::getenv("QUERY_STRING"));
    std::string str;

    while (getline(raw, str, '&'))
    {
        std::string name, value;
        std::istringstream var(str);

        getline(var, name, '=');
        getline(var, value, '=');

        if (!name.empty())
            data[name] = value;
    }

    return data;
}
