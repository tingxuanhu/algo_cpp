#include <iostream>
#include <string>

using namespace std;

void swap(char &a, char &b)
{
  char tmp = a;
  a = b;
  b = tmp;
}

void reverseRange(string &s, int begin, int end)
{
  for (int i = begin, j = end; i < j; i++, j--)
  {
    swap(s[i], s[j]);
  }
}

int main()
{

  // input
  string s;
  // cout << s;

  while (getline(cin, s))
  {

    int slow = 0, fast = 0;
    // ================== remove blanks =====================
    // remove blanks in the beginning
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ‘)
    {
      fast++;
    }

    for (; fast < s.size(); ++fast)
    {
      // remove blanks in the middle
      if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ’ ‘)
        continue;
      else
        s[slow++] = s[fast];
    }

    // remove blanks in the end
    if (slow - 1 > 0 && s[slow - 1] == ’ ‘)
      s.resize(slow - 1);
    else
      s.resize(slow);


    // ===================== reverse the whole string ====================
    reverseRange(s, 0, s.size() - 1);

    // ====================== reverse each word =======================
    int start = 0; // after blank clearing, the first word should not be blank
    for (int i = 0; i <= s.size(); ++i) // because we need to tackle the last word, i <= rather than < s.size()
    {
      if (i == s.size() || s[i] == ' ’)  // i == s.size() is for the last word reversion
      {
        reverseRange(s, start, i - 1);
        start = i + 1;
      }
    }
    cout << s << endl;

  }

  return 0;
}
