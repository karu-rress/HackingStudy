#include <algorithm>
#include <chrono>
#include <concepts>
#include <deque>
#include <format>
#include <iostream>
#include <random>
#include <string_view>
#include <type_traits>

#include "hidestring.hpp"

using namespace std;

#pragma region CORE_SPACE
// constexpr string FLAG_REAL_1 = "DH{why_don'7_y0u_j0in_ro11in6_r3ss????}";
// constexpr string FLAG_FAKE = "k9#Vp@2Z!xL$8cQ&5mN*7bY^";
#pragma endregion

// The fake flag that users should guess
DEFINE_ON_THE_FLY_STRING(TargetKey, 0x57, ('k')('9')('#')('V')('p')('@')('2')('Z')('!')('x')('L')('$')('8')('c')('Q')('&')('5')('m')('N')('*')('7')('b')('Y')('^'))

static constexpr std::string_view charlist = "0123456789"
                                             "`~!@$%^*+-_=:;?<>"
                                             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                             "abcdefghijklmnopqrstuvwxyz";

// 진짜 플래그 암호화 데이터 (Real Flag XOR TargetKey)
// Real: R0111n6_R355_15_4_r361573r3d_tr4d3m4rk (38 bytes)
// Key : k9#Vp@2Z!xL$8cQ&5mN*7bY^ (24 bytes, 반복 적용)
const unsigned char encrypted_real_flag[] = {
    0x19, 0x09, 0x12, 0x27, 0x41, 0x2E, 0x04, 0x05, 0x73, 0x4B,
    0x19, 0x11, 0x27, 0x52, 0x74, 0x69, 0x01, 0x32, 0x3C, 0x19,
    0x01, 0x53, 0x6C, 0x79, 0x58, 0x4B, 0x10, 0x12, 0x11, 0x54,
    0x40, 0x7E, 0x45, 0x4B, 0x21, 0x10, 0x4A, 0x08};

void find_in_str(char ch, int current_turn, int threshold, bool is_corrupted) {
    // 분기문(if) 없이 상태값을 0 또는 1로 계산하여 상태 결정을 강제합니다.
    int over_threshold = (current_turn > threshold) || is_corrupted;

    bool found = false;
    for (size_t i = 0; i < GetTargetKey::length; ++i) {
        char actual_char = GetTargetKey::get(i);
        char fake_char = charlist[(ch * i + current_turn) % (sizeof(charlist) - 1)];

        // over_threshold가 1이면 가짜 문자를, 0이면 진짜 문자를 산술 연산으로 선택
        char compare_char = (over_threshold * fake_char) | ((1 - over_threshold) * actual_char);

        if (ch == compare_char) {
            // C++20 std::format 적용
            cout << std::format("**** '{}' first appears in index {}.\n", ch, i);
            found = true;
            break;
        }
    }

    if (!found) {
        // C++20 std::format 적용
        cout << std::format("**** '{}' is not in flag.\n", ch);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        size_t key_len = strlen(argv[1]);
        if (key_len == 0)
            key_len = 1; // Prevent division by zero

        string decrypted_flag;
        for (size_t i = 0; i < sizeof(encrypted_real_flag); ++i) {
            decrypted_flag += encrypted_real_flag[i] ^ argv[1][i % key_len];
        }

        cout << std::format("The flag is:\nDH{{{}}}\n", decrypted_flag);
        cout << "But... are you sure this is the correct key?" << endl;
        return 0;
    }
    else if (argc != 4) {
        cout << "Argument error occured! Aboring..." << endl;
        return 1;
    }

    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<int> dis{3, 7};
    const int threshold{dis(gen)};

    deque<char> inputs;
    bool is_corrupted = false;

    for (char ch{}; int i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        cout << format("[{:02}] Input a character >> ", i);
        cin >> ch;

        if (inputs.size() >= 3)
            inputs.pop_front();
        inputs.push_back(ch);

        if (inputs.size() >= 3 && !ranges::search(charlist, inputs).empty()) {
            cout << "\n##### You may not want to use bruteforce attack!" << endl;
            is_corrupted = true;
        }

        find_in_str(ch, i, threshold, is_corrupted);
    }

    cout << "\n##### Max input times reached! Shutting down..." << endl;
    return 0;
}