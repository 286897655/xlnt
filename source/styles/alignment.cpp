// Copyright (c) 2014-2015 Thomas Fussell
// Copyright (c) 2010-2015 openpyxl
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, WRISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file

#include <xlnt/styles/alignment.hpp>

namespace xlnt {

bool alignment::get_wrap_text() const
{
    return wrap_text_;
}

void alignment::set_wrap_text(bool wrap_text)
{
    wrap_text_ = wrap_text;
}

bool alignment::has_horizontal() const
{
    return horizontal_ != horizontal_alignment::none;
}

horizontal_alignment alignment::get_horizontal() const
{
    return horizontal_;
}

void alignment::set_horizontal(horizontal_alignment horizontal)
{
    horizontal_ = horizontal;
}

bool alignment::has_vertical() const
{
    return vertical_ != vertical_alignment::none;
}

vertical_alignment alignment::get_vertical() const
{
    return vertical_;
}

void alignment::set_vertical(vertical_alignment vertical)
{
    vertical_ = vertical;
}

bool alignment::operator==(const alignment &other) const
{
    return hash() == other.hash();
}

std::size_t alignment::hash() const
{
    std::size_t seed = 0;
    hash_combine(seed, wrap_text_);
    hash_combine(seed, shrink_to_fit_);
    hash_combine(seed, static_cast<std::size_t>(horizontal_));
    hash_combine(seed, static_cast<std::size_t>(vertical_));
    hash_combine(seed, text_rotation_);
    hash_combine(seed, indent_);
    return seed;
}

} // namespace xlnt