

#include <cstdlib>
#include <iostream>

#define NUM_ENV         32

const std::string ENV[ NUM_ENV ] = {
    "AUTH_TYPE", "COMSPEC", "CONTENT_LENGTH",
    "CONTENT_TYPE", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
    "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING", "HTTP_ACCEPT_LANGUAGE",
    "HTTP_CONNECTION", "HTTP_HOST", "HTTP_USER_AGENT",
    "PATH", "PATH_INFO", "PATH_TRANSLATED",
    "QUERY_STRING", "REMOTE_ADDR", "REMOTE_HOST",
    "REMOTE_IDENT", "REMOTE_PORT", "REMOTE_USER",
    "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
    "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
    "SERVER_NAME", "SERVER_PORT", "SERVER_PROTOCOL",
    "SERVER_SIGNATURE", "SERVER_SOFTWARE"
};

int main ()
{
    std::cout << "Content-type:text/html\r\n\r\n";
    std::cout << "<html>\n";
    std::cout << "<head>\n";
    std::cout << "<title>CGI Envrionment Variables</title>\n";
    std::cout << "</head>\n";
    std::cout << "<body>\n";
    std::cout << "<table border = \"0\" cellspacing = \"2\">";

    for (int i = 0; i < NUM_ENV; i++)
    {
        std::cout << "<tr><td>" << ENV[ i ] << "</td><td>";
        // attempt to retrieve value of environment variable
        char *value = std::getenv( ENV[ i ].c_str() );
        if ( value != 0 )
            std::cout << value;
        else
            std::cout << "Environment variable does not exist.";
        std::cout << "</td></tr>\n";
    }
    std::cout << "</table>\n";
    std::cout << "</body>\n";
    std::cout << "</html>\n";

    return 0;
}
