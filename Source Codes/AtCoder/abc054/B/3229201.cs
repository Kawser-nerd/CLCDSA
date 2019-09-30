using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var num1 = ToInt32(input[0]);
        var num2 = ToInt32(input[1]);

        var PicA = new string[num1];
        var PicB = new string[num2];
        for (var i = 0; i < num1 + num2; i++)
        {
            var str = ReadLine();
            if (i < num1) PicA[i] = str;
            else PicB[i % num1] = str;
        }

        for (var i = 0; i < num1; i++)
        {
            var counter = 0;
            var isSame = true;
            while (true)
            {
                if (!PicA[i].Contains(PicB[0])) { isSame = false; break; }
                var index = PicA[i].IndexOf(PicB[0],counter*PicB.Length);
                if (index == -1||PicA.Length-i-PicB.Length<0) { isSame = false; break; }
               isSame = true;
                for (var j = 1; j < num2; j++)
                {
                    for(var h = 0; h < PicB[j].Length; h++)
                    {
                        if (!(PicA[j+i].Substring(index + h, 1) == PicB[j].Substring(h, 1))) { isSame = false; break; }
                    }
                    if (!isSame) break;
                }
                if (isSame) { WriteLine("Yes");break; }
                counter++;
            }
            if (isSame) break;
            if (i == num1 - 1) WriteLine("No");
        }
    }
}