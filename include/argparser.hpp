// ArgParse - A Command Line Argument Parser for C++
// Copyright (C) 2008 Ingo Ruhnke <grumbel@gmail.com>
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

#ifndef HEADER_ARGPARSER_ARG_PARSER_HPP
#define HEADER_ARGPARSER_ARG_PARSER_HPP

#include <vector>
#include <string>

namespace argparser {

class ArgParser
{
private:
  struct Option
  {
    int key = {};
    char        short_option = {};
    std::string long_option = {};
    std::string help = {};
    std::string argument = {};
    bool visible = {};
  };

public:
  struct ParsedOption
  {
    int key = -1;
    std::string option = {};
    std::string argument = {};
  };

  enum {
    REST_ARG  = -1,
    TEXT      = -4,
    USAGE     = -5,
    PSEUDO    = -6
  };

  typedef std::vector<ParsedOption> ParsedOptions;

public:
  ArgParser();

  ArgParser& add_usage(const std::string& usage);
  ArgParser& add_text(const std::string& text);
  ArgParser& add_pseudo(const std::string& left, const std::string& doc);
  ArgParser& add_newline();

  ArgParser& add_option(int key,
                        char short_option,
                        const std::string& long_option,
                        const std::string& argument,
                        const std::string& help,
                        bool visible = true);

  ParsedOptions parse_args(int argc, char** argv);
  void print_help(std::ostream& out) const;

private:
  void read_option(int id, const std::string& argument);

  /** Find the Option structure that matches \a short_option */
  Option const* lookup_short_option(char short_option) const;

  /** Find the Option structure that matches \a long_option */
  Option const* lookup_long_option (const std::string& long_option) const;

private:
  std::string m_programm;
  std::vector<Option> m_options;
};

} // namespace argparser

#endif

/* EOF */
