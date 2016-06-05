/*
 * CWeb is an simple CGI application using C++.
 * Copyright (C) 2016 Sigifredo Escobar Gómez <sigifredo89@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


// Own
#include <Application.hpp>

// std
#include <string>

Application::Application()
{
    std::string requesMethod(std::getenv("REQUEST_METHOD"));

    if (requesMethod.compare("GET") == 0)
        _eRequestMethod = GET;
    else if (requesMethod.compare("HEAD") == 0)
        _eRequestMethod = HEAD;
    else if (requesMethod.compare("POST") == 0)
        _eRequestMethod = POST;
    else if (requesMethod.compare("PUT") == 0)
        _eRequestMethod = PUT;
    else if (requesMethod.compare("DELETE") == 0)
        _eRequestMethod = DELETE;
    else if (requesMethod.compare("TRACE") == 0)
        _eRequestMethod = TRACE;
    else if (requesMethod.compare("CONNECT") == 0)
        _eRequestMethod = CONNECT;
}
