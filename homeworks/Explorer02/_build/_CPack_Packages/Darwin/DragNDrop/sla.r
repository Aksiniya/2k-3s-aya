#include <CoreServices/CoreServices.r>

data 'LPic' (5000) {
    $"0002 0011 0003 0001 0000 0000 0002 0000"
    $"0008 0003 0000 0001 0004 0000 0004 0005"
    $"0000 000E 0006 0001 0005 0007 0000 0007"
    $"0008 0000 0047 0009 0000 0034 000A 0001"
    $"0035 000B 0001 0020 000C 0000 0011 000D"
    $"0000 005B 0004 0000 0033 000F 0001 000C"
    $"0010 0000 000B 000E 0000"
};


data 'TEXT' (5002, "English") {
        "MIT License"
        "\n"
        "\n"
        "Copyright (c) 2017 Nadezda Agildina"
        "\n"
        "\n"
        "Permission is hereby granted, free of charge, to any person obtaining a copy"
        "\n"
        "of this software and associated documentation files (the \"Software\"), to deal"
        "\n"
        "in the Software without restriction, including without limitation the rights"
        "\n"
        "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell"
        "\n"
        "copies of the Software, and to permit persons to whom the Software is"
        "\n"
        "furnished to do so, subject to the following conditions:"
        "\n"
        "\n"
        "The above copyright notice and this permission notice shall be included in all"
        "\n"
        "copies or substantial portions of the Software."
        "\n"
        "\n"
        "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR"
        "\n"
        "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,"
        "\n"
        "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE"
        "\n"
        "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER"
        "\n"
        "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,"
        "\n"
        "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE"
        "\n"
        "SOFTWARE."
        "\n"
        "\n"
};

resource 'STR#' (5002, "English") {
    {
        "English",
        "Agree",
        "Disagree",
        "Print",
        "Save...",
        "You agree to the License Agreement terms when you click "
        "the \"Agree\" button.",
        "Software License Agreement",
        "This text cannot be saved.  This disk may be full or locked, or the "
        "file may be locked.",
        "Unable to print.  Make sure you have selected a printer."
    }
};

