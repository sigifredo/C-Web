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

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

class Application
{
public:
    enum RequestMethod { GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT };

    Application();

    RequestMethod requestMethod() const;

private:
    RequestMethod _eRequestMethod;
};

inline Application::RequestMethod Application::requestMethod() const
{
    return _eRequestMethod;
}

#endif
