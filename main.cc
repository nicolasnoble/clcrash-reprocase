#include <iomanip>
#include <iostream>
#include <tuple>
#include <type_traits>
#include "typestring.hh"

template <typename type, type defaultValue, typename name>
class Setting;
template <typename type, type defaultValue, char... C>
class Setting<type, defaultValue, irqus::typestring<C...>> {
  public:
	type value = defaultValue;
};


typedef typestring_is("Abcdef") Str1;
typedef typestring_is("Ghijkl") Str2;
typedef typestring_is("Mnopqr") Str3;
typedef typestring_is("Stuvwx") Str4;
typedef typestring_is("Yzabcd") Str5;
typedef typestring_is("Efghij") Str6;
typedef typestring_is("Klmnop") Str7;
typedef typestring_is("Qrstuv") Str8;

typedef Setting<bool, true, Str1> Set1;
typedef Setting<int, 3, Str2> Set2;
typedef Setting<bool, true, Str3> Set3;
typedef Setting<bool, true, Str4> Set4;
typedef Setting<int, 2, Str5> Set5;
typedef Setting<int, 2, Str6> Set6;
typedef Setting<bool, false, Str7> Set7;
typedef Setting<bool, false, Str8> Set8;

std::tuple<Set1, Set2, Set3, Set4, Set5, Set6, Set7, Set8> container;

int main() {
	std::get<Set1>(container).value = false;
	return 0;
}
