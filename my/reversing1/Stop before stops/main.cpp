#include "reversing01.hpp"
#include <cstring>

using namespace std;

#pragma region CORE_SPACE
    // constexpr string FLAG_REAL_1 = "DH{why_don'7_y0u_j0in_ro11in6_r3ss????}";
    // constexpr string FLAG_FAKE_2 = "BcREx1TUe?mB=i:<Sx_qpJW4";
#pragma endregion

void find_in_str(char ch, string flag)
{
    if (auto result{flag.find(ch)}; result == string::npos)
        cout << "**** \'" << ch << "\' is not in flag." << endl;
    else
        cout << "**** \'" << ch << "\' first appears in index " << result << "." << endl;
}

int main(int argc, char* argv[])
{
    [[maybe_unused]] const char * special_chars = "`~!@$%^*+-_=:;?<>";
    
    switch (argc)
    {
        [[likely]] case 0x03: // gussing
            break;

        case 0x02: // flag input
            if (std::strlen(argv[1]) == 24 && vlkjbkldsajfksdkfl2 == argv[1])
            {
                cout << "Congratulations! The flag is: " << endl;
                cout << "DH{" << lkjasvhkjsldhkl << "}" << endl;
                return 0;
            }
            else
                [[fallthrough]];
            
        default:
            cout << "Argument error occured! Aborting..." << endl;
            return 1;
    }

    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<int> dis{3, 7};
    const int threshold{dis(gen)};
    deque<char> inputs;

    for (char ch{}; int i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
    {
        if (i > threshold)
            vlkjbkldsajfksdkfl2 = generate_random_string();

        cout.put('[');
        cout.width(2);
        cout.fill('0');
        cout << i << "] Input a character >> ";
        cin >> ch;

        if (inputs.size() >= 3)
            inputs.pop_front();
        inputs.push_back(ch);

        if (inputs.size() >= 3 && charstr.find(string{inputs.begin(), inputs.end()}) != string::npos)
        {
            cout << "\n##### Bruteforce attack is not allowed! Aborting..." << endl;
            return 1;
        }

        find_in_str(ch, vlkjbkldsajfksdkfl2);
    }

    cout << "\n##### Max input times reached! Shutting down..." << endl;
    return 0;
}