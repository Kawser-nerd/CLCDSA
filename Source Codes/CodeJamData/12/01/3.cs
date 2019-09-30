using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamQR2012
{
    class Program
    {
        static private string Translate(string textToTranslate, char[] map)
        {
            string ret = "";
            foreach (char c in textToTranslate)
            {
                if (c == ' ')
                {
                    ret += ' ';
                }
                else
                {
                    ret += map[c - 'a'];
                }
            }
            return ret;
        }

        static private void QR_A()
        {
            char[] englishChars = new char[26];
            char[] googlereseChars = new char[26];

            string[] knownEnglish = {
                                        "a",
                                        "o",
                                        "z",
                                        "our language is impossible to understand",
                                        "there are twenty six factorial possibilities",
                                        "so it is okay if you want to just give up"
                                    };
            string[] knownGooglerese = {
                                           "y",
                                           "e",
                                           "q",
                                           "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                                           "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                                           "de kr kd eoya kw aej tysr re ujdr lkgc jv"
                                     };

            for (int i = 0; i < 26; ++i)
            {
                englishChars[i] = '?';
                googlereseChars[i] = '?';
            }

            for (int i = 0; i < 26; ++i)
            {
                char currentChar = (char)('a' + i);

                for (int j = 0; j < knownEnglish.Length; ++j)
                {
                    string eng = knownEnglish[j];
                    string goo = knownGooglerese[j];

                    int charPos = eng.IndexOf(currentChar);
                    if (charPos != -1)
                    {
                        char gChar = goo[charPos];

                        //currentChar maps to gChar.
                        englishChars[i] = gChar;
                        googlereseChars[gChar - 'a'] = currentChar;
                        break;
                    }
                }
            }

            // q maps to something, but what?
            int unknownEnglishCount = englishChars.Count(c => c == '?');
            int unknownGooglerCount = googlereseChars.Count(c => c == '?');
            int eUnknownIndex = new List<char>(englishChars).IndexOf('?');
            int gUnknownIndex = new List<char>(googlereseChars).IndexOf('?');
            englishChars[eUnknownIndex] = (char)('a' + gUnknownIndex);
            googlereseChars[gUnknownIndex] = (char)('a' + eUnknownIndex);

            // now do the work
            int numLines = Int32.Parse(Console.ReadLine());
            for (int zz = 0; zz < numLines; zz++)
            {
                string gText = Console.ReadLine();
                string eText = Translate(gText, googlereseChars);

                Console.WriteLine(String.Format("Case #{0}: {1}", zz + 1, eText));
            }
        }

        static void Main(string[] args)
        {
            QR_A();
        }
    }
}
