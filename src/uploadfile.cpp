

#include <cstdio>
#include <cstdlib>
#include <string>

#define HTML_HEADER     "<html> \
                            <head> \
                                <title>File upload</title> \
                            </head> \
                            <body>"
#define HTML_FORM       "       <form enctype=\"multipart/form-data\" action=\"uploadfile.cgi\" method=\"post\"> \
                                    <p>File: <input type=\"file\" name=\"userfile\" /></p> \
                                    <p><input type=\"submit\" value=\"Upload\" /></p> \
                                </form>"
#define HTML_FOOTER     "   </body> \
                        </html>"


int main ()
{
    std::printf("Content-type:text/plain\r\n\r\n");
    std::printf(HTML_HEADER);

    std::string requestType(std::getenv("REQUEST_METHOD"));

    if (requestType.compare("POST") == 0 || requestType.compare("post") == 0)
    {
        long len = std::strtol(std::getenv("CONTENT_LENGTH"), nullptr, 10);
        char * data = new char[len+1];

        std::printf("CONTENT_LENGTH: %d\n", len);

        if (std::fgets(data, len+1, stdin))
        {
            // FILE * tmpfile = std::tmpfile();
            // std::fputs(data, tmpfile);

            for (int i = 0; i < len+1; i++)
                std::printf("0x%x, ", data[i]);

            // std::fclose(tmpfile);
        }

        delete [] data;
    }
    else
        std::printf(HTML_FORM);

    std::printf(HTML_FOOTER);
}
