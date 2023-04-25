#pragma once

#include <iostream>
#include <string_view>
#include <random>
#include <chrono>
#include <type_traits>
#include <concepts>
#include <deque>

#include "hidestring.hpp"

DEFINE_HIDDEN_STRING(Rare1, 0x51, ('w')('h')('y'))
DEFINE_HIDDEN_STRING(Rare2, 0x52, ('d')('o')('n')('\'')('7'))
DEFINE_HIDDEN_STRING(Rare3, 0x53, ('y')('0')('u'))
DEFINE_HIDDEN_STRING(Rare4, 0x54, ('j')('0')('i')('n'))
DEFINE_HIDDEN_STRING(Rare5, 0x55, ('r')('o')('1')('1')('i')('n')('6'))
DEFINE_HIDDEN_STRING(Rare6, 0x56, ('r')('3')('s')('s')('?')('?')('?')('?'))
DEFINE_HIDDEN_STRING(Rare7, 0x57, ('B')('c')('R')('E')('x')('1')('T')('U')('e')('?')('m')('B')('=')('i')(':')('<')('S')('x')('_')('q')('p')('J')('W')('4'))
DEFINE_HIDDEN_STRING(Rare8, 0x58, ('S')('H')('F')('@')('$')('K')('J')('2')('o')('i')('3')('D')('$')('j')('f')('u')('9')('8')('2'))

static const char charlist[] =
    "0123456789"
    "`~!@$%^*+-_=:;?<>"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
const std::string charstr(charlist);


class part1 {
public:
    inline const static std::string_view segment = GetRare1();
};

class part2 : public part1 {
public:
    inline const static std::string_view segment = GetRare2();
};

class part3 : public part2 {
public:
    inline const static std::string_view segment = GetRare3();
};

class part4 : public part3 {
public:
    inline const static std::string_view segment = GetRare4();
};

class part5 : public part4 {
public:
    inline const static std::string_view segment = GetRare5();
};

class part6 : public part5 {
public:
    inline const static std::string_view segment = GetRare6();
};

template<typename T>
concept part_of_flag = std::derived_from<T, part1> || std::is_same_v<T, part1>;

template<typename T> requires part_of_flag<T>
const std::string get_segment() {
    return std::string{T::segment};
}

const std::string get_flag1() {
    const char dash{'_'};
    return get_segment<part1>() + dash
        + get_segment<part2>() + dash
        + get_segment<part3>() + dash
        + get_segment<part4>() + dash
        + get_segment<part5>() + dash
        + get_segment<part6>();
}

const std::string get_flag2() {
    return std::string{GetRare7()};
}

const std::string get_flag3() {
    return std::string{GetRare8()};
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