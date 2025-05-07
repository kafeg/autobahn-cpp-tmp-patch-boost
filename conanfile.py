from conan import ConanFile
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import cmake_layout, CMake
from conan.tools.files import copy
import os

class autobahn_cppConan(ConanFile):
    name = "autobahn-cpp"
    version = "22.0.0"
    license = "Boost Software License - Version 1.0 - August 17th, 2003"
    author = "Crossbar.io Technologies GmbH and contributors"
    description = "WAMP for C++ on Boost/ASIO"
    url = "https://github.com/crossbario/autobahn-cpp"
    generators = "CMakeToolchain", "CMakeDeps"
    # Settings below are required for building the examples
    settings = "compiler", "build_type"
    scm = {
        "type": "git",
        "subfolder": ".",
        "url": "auto",
        "revision": "auto"
    }
    exports_sources = "autobahn/*", "examples/*", "CMakeLists.txt"
    no_copy_source = True
    package_type = "header-library"

    def requirements(self):
        self.requires("msgpack-cxx/[>=4.0.3]")
        self.requires("websocketpp/[>=0.8.2]")
        self.requires("boost/[>=1.73.0]")
        if self.conf.get("user.autobahn:use_botan", default=False):
            self.output.info("USE BOTAN == TRUE")
            self.requires("botan/[>=2.17.3]")

    def validate(self):
        check_min_cppstd(self, 14)

    def layout(self):
        cmake_layout(self)

    def build(self):
        if not self.conf.get("user.autobahn:skip_examples", default=False):
            cmake = CMake(self)
            use_botan = self.conf.get("user.autobahn:use_botan", default=False)
            cmake.configure(variables={"AUTOBAHN_BUILD_EXAMPLES_BOTAN": "ON" if use_botan else "OFF"})
            cmake.build()

    def package(self):
        copy(self, "*.hpp", self.source_folder, os.path.join(self.package_folder, "include"), excludes=["examples"])
        copy(self, "*.ipp", self.source_folder, os.path.join(self.package_folder, "include"), excludes=["examples"])

    def package_id(self):
        self.info.clear()

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
