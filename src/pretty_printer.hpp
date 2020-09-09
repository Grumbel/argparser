/*
**  Xbox360 USB Gamepad Userspace Driver
**  Copyright (C) 2008 Ingo Ruhnke <grumbel@gmail.com>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HEADER_PRETTY_PRINTER_HPP
#define HEADER_PRETTY_PRINTER_HPP

#include <string_view>
#include <ostream>
#include <iostream>

class PrettyPrinter
{
public:
  PrettyPrinter(int terminal_width, std::ostream& out = std::cout);

  void print(std::string_view text) const;
  void print(std::string_view indent, std::string_view initial, std::string_view text) const;

private:
  int terminal_width;
  std::ostream& m_out;
};

#endif

/* EOF */
