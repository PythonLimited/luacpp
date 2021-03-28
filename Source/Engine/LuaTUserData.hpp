/*
   MIT License

   Copyright (c) 2021 Jordan Vrtanoski

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
   */


#ifndef LUACPP_LUATUSERDATA_HPP
#define LUACPP_LUATUSERDATA_HPP

#include <map>

#include "../Lua.hpp"
#include "LuaState.hpp"
#include "LuaType.hpp"

namespace LuaCpp {
	namespace Engine {
		class LuaTUserData : public LuaType {
		   protected:
			void *userdata;
			size_t size;

			std::map<std::string, lua_CFunction> metatable;

			virtual void _storeData();
			virtual void _retreiveData();
		   public:
			LuaTUserData(size_t _size) : size(_size), LuaType(), userdata(NULL), metatable() {}
			~LuaTUserData() {}

			int getTypeId();
			std::string getTypeName(LuaState &L);
			void PushValue(LuaState &L);
			void PopValue(LuaState &L, int idx);
			std::string ToString();

			void *getRawUserData();

			void AddMetaFunction(std::string fname, lua_CFunction fn);

		};
	}
}
#endif // LUACPP_LUATUSERDATA_HPP

