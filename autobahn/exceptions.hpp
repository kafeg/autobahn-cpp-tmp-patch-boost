///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Crossbar.io Technologies GmbH and contributors
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef AUTOBAHN_EXCEPTIONS_HPP
#define AUTOBAHN_EXCEPTIONS_HPP

#include <string>
#include <stdexcept>

namespace autobahn {

class abort_error : public std::runtime_error {
  public:
     abort_error(const std::string& message) : std::runtime_error(message) {}
};

class network_error : public std::runtime_error {
  public:
     network_error(const std::string& message) : std::runtime_error(message) {}
};

class no_session_error : public std::runtime_error {
  public:
     no_session_error() : std::runtime_error("session not joined") {}
};

class no_transport_error : public std::runtime_error {
  public:
     no_transport_error() : std::runtime_error("session not attached") {}
};

class protocol_error : public std::runtime_error {
  public:
     protocol_error(const std::string& message) : std::runtime_error(message) {}
};

} // namespace autobahn

#endif // AUTOBAHN_EXCEPTIONS_HPP
