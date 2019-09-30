using System;
using System.Linq;
using System.Collections.Generic;

public class MainProgram
{
    public static void Main(string[] args)
    {
        new SRC71C().Start();
    }

}
//????????????
public class SRC71C
{
    public void Start()
    {
        Solve();
    }

    public void Solve()
    {
        int num = int.Parse(Console.ReadLine().Trim());
        var words = new List<string>();
        var min = int.MaxValue;
        var minWord = "";
        for(int i = 0;i < num;i++){
            string word = Console.ReadLine().Trim();
            words.Add(word);
            if(word.Length < min){
                minWord = word;
                min = word.Length;
            }
        }

        string result = FindStringSet(words,minWord);

        Console.WriteLine(result);

    }

    string FindStringSet(List<String> words,string minWord)
    {
        char[] minWordChars =Utility.GetAlphabet().ToArray();//minWord.ToCharArray();
        var resultChars = new List<char>();
        for(int i= 0,l = minWordChars.Length;i<l;i++){
            char ch =minWordChars[i];
            if(IsExistInAllWord(words,ch))
            {
                for(int j = 0,jl = FindMinNum(words,ch);j<jl;j++){
                    resultChars.Add(ch);
                }
            }
        }

        return new String(resultChars.ToArray());

    }

    int FindMinNum(List<String> words,char word)
    {
        int min = int.MaxValue;
        for(int all = 0,allLength = words.Count;all<allLength;all++){
            min = Math.Min(min,Utility.CountChar(words[all],word));
        }

        return min;
    }

    bool IsExistInAllWord(List<String> words,char word)
    {
        for(int all = 0,allLength = words.Count;all<allLength;all++){
            if(!words[all].Contains(word.ToString()))
            {
                return false;
            }
        }
        return true;
    }

public static class Utility
{
    public static void OutPutResult(List<string> resultLines)
    {
        for (int i = 0, l = resultLines.Count; i < l; i++)
        {
            Console.WriteLine(resultLines[i]);
        }
    }

    public static List<char> GetAlphabet()
    {
        List<char> result = new List<char>();
        const int Size = 'z'-'a';
        char alpha = 'a'; 
        for(int i = 0;i<=Size;i++){
            result.Add(alpha++);
        }

        return result;
    }

    public static int CountCharIgnoreCase(string s, char c) {
        return s.ToLower().Where(c1 => c1==char.ToLower(c)).Count();
    }

    public static int CountChar(string s, char c) {
        return s.Where(c1 => c1==c).Count();
    }

    public static void SortStringArray(string[] stringArray)
    {
        StringComparer cmp = StringComparer.OrdinalIgnoreCase;
        Array.Sort(stringArray, cmp);
    }

    public static void SortArray<T>(T[] target)
    {
        StringComparer cmp = StringComparer.OrdinalIgnoreCase;
        Array.Sort(target, cmp);
    }
}

}