// ArgParser
// Copyright (C) 2015 Ingo Ruhnke <grumbel@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <argparser.hpp>
#include <iostream>

int main(int argc, char** argv)
{
  try
  {
    argparser::ArgParser parser;

    parser
      .add_usage("bar [FILES]... [BLA]..")
      .add_usage("foo [FILES]... [BLA]..")
      .add_text("Dies und das")
      .add_newline()
      .add_option(1, 'v', "version", "", "Help text");

    parser.parse_args(argc, argv);

    return 0;
  }
  catch(const std::exception& err)
  {
    std::cout << "Error: " << err.what() << std::endl;
    return 1;
  }
}

/* EOF */
