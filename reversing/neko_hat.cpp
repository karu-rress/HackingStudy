#include <iostream>
#include <cstring>

using namespace std;

long long refine(char* buf)
{
  char *buf_ptr; // [rsp+8h] [rbp-18h]
  int v3; // [rsp+10h] [rbp-10h]
  int i; // [rsp+14h] [rbp-Ch]
  long long v5; // [rsp+18h] [rbp-8h]

  buf_ptr = buf;
  v5 = 0LL;
  v3 = strlen(buf);
  for ( i = 0; i < v3; ++i )
  {
    if ( *buf_ptr <= 47 || *buf_ptr > 57 )
    {
      if ( *buf_ptr <= 64 || *buf_ptr > 70 )
      {
        if ( *buf_ptr > 96 && *buf_ptr <= 102 )
          v5 = 16 * v5 + *buf_ptr - 87;
      }
      else
      {
        v5 = 16 * v5 + *buf_ptr - 55;
      }
    }
    else
    {
      v5 = 16 * v5 + *buf_ptr - 48;
    }
    ++buf_ptr;
  }
  return v5;
}

int main()
{
  long long alpha{0x62f0aaba};
  long long beta{0xa1f2ddf600};
  long long gamma{0x2232c1f8e3};
  long long delta{0x517f9764};

  string buf;
  cin >> buf;

  cout << hex << refine(const_cast<char*>(buf.c_str()));
  return 0;
}