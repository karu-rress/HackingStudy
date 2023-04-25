#pragma once

#include <iostream>
#include <string_view>
#include <random>
#include <chrono>
#include <type_traits>
#include <concepts>
#include <deque>

#include "hidestring.hpp"

DEFINE_HIDDEN_STRING(sfhlkhfk2, 0x52, ('d')('o')('n')('\'')('7'))
DEFINE_HIDDEN_STRING(vashuoiuewhli, 0x58, ('S')('H')('F')('@')('$')('K')('J')('2')('o')('i')('3')('D')('$')('j')('f')('u')('9')('8')('2'))
DEFINE_HIDDEN_STRING(xbncdjbvk2, 0x51, ('w')('h')('y'))
DEFINE_HIDDEN_STRING(lsdhkflkh3il, 0x54, ('j')('0')('i')('n'))
DEFINE_HIDDEN_STRING(fldhuui2738, 0x56, ('r')('3')('s')('s')('?')('?')('?')('?'))
DEFINE_HIDDEN_STRING(lskdhfkjlhj3, 0x53, ('y')('0')('u'))
DEFINE_HIDDEN_STRING(ksdflhkhiuhl2, 0x55, ('r')('o')('1')('1')('i')('n')('6'))
DEFINE_HIDDEN_STRING(slifdhiuil3, 0x57, ('B')('c')('R')('E')('x')('1')('T')('U')('e')('?')('m')('B')('=')('i')(':')('<')('S')('x')('_')('q')('p')('J')('W')('4'))

static const char charlist[] =
    "0123456789"
    "`~!@$%^*+-_=:;?<>"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
const std::string charstr(charlist);

class qoieuryht93qufi {
public:
    inline const static std::string_view segment = Getxbncdjbvk2();
};

class zdhf98w49837 : public qoieuryht93qufi {
public:
    inline const static std::string_view segment = Getsfhlkhfk2();
};

class fvopij3opji4 : public zdhf98w49837 {
public:
    inline const static std::string_view segment = Getlskdhfkjlhj3();
};

class sldjhvhiu3hi43 : public fvopij3opji4 {
public:
    inline const static std::string_view segment = Getlsdhkflkh3il();
};

class lkjshkjvhiuh2 : public sldjhvhiu3hi43 {
public:
    inline const static std::string_view segment = Getksdflhkhiuhl2();
};

class oiuvdhoiau3 : public lkjshkjvhiuh2 {
public:
    inline const static std::string_view segment = Getfldhuui2738();
};

template<typename T>
concept part_of_flag = std::derived_from<T, qoieuryht93qufi> || std::is_same_v<T, qoieuryht93qufi>;

template<typename T> requires part_of_flag<T>
const std::string hilcvfhluh3() {
    return std::string{T::segment};
}

const std::string vhlkjhadskufhuli3() {
    const char dash{'_'};
    return hilcvfhluh3<qoieuryht93qufi>() + dash
        + hilcvfhluh3<zdhf98w49837>() + dash
        + hilcvfhluh3<fvopij3opji4>() + dash
        + hilcvfhluh3<sldjhvhiu3hi43>() + dash
        + hilcvfhluh3<lkjshkjvhiuh2>() + dash
        + hilcvfhluh3<oiuvdhoiau3>();
}


class salkdhvkhlklhkjfdhkjd : public oiuvdhoiau3 {
public:
    inline const static std::string_view segment = Getslifdhiuil3();
};

const std::string sldkhjlhvfiuh() {
    return std::string{salkdhvkhlklhkjfdhkjd::segment};
}

const std::string hisdvluihilj3() {
    return std::string{Getvashuoiuewhli()};
}

std::string generate_random_string() {
    constexpr int size{24};
    std::string tmp_s;
    tmp_s.reserve(size);

    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<int> dis{0, sizeof(charlist) - 1};

    for (int i{}; i < size; ++i) {
        tmp_s += charlist[dis(gen)];
    }
    
    return tmp_s;
}

std::string lkjasvhkjsldhkl{vhlkjhadskufhuli3()};
std::string vlkjbkldsajfksdkfl2{sldkhjlhvfiuh()};