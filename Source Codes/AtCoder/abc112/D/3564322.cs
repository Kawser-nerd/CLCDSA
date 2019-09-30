using System;
using System.Text;

class Program
{
  static void Main(string[] args)
  {
    string[] l_sPins = Console.ReadLine().Split(' ');
    int l_iN = int.Parse(l_sPins[0]);
    int l_iM = int.Parse(l_sPins[1]);

    int iRet = 1;
    for (int i = l_iM / l_iN; 1 <= i; i--)
    {
      if (l_iM % i == 0 && l_iN <= (l_iM / i))
      {
        iRet = i;
        Console.WriteLine(iRet);
        break;
      }
    }
  }
}