using static System.Console;

class Program
{
    enum State
    {
        A,
        B,
        C,
    }

    static void Main(string[] args)
    {
        var strA = ReadLine();
        var strB = ReadLine();
        var strC = ReadLine();
        var state = State.A;
        var result = "";
        while (true)
        {
            switch (state)
            {
                case State.A:
                    if (strA.Length == 0) { result = "A";break; }
                    ChangeState(ref state, strA.Substring(0, 1));
                    strA = strA.Substring(1);
                    break;
                case State.B:
                    if (strB.Length == 0) { result = "B";break; }
                    ChangeState(ref state, strB.Substring(0, 1));
                    strB = strB.Substring(1);
                    break;
                case State.C:
                    if (strC.Length == 0) { result = "C";break; }
                    ChangeState(ref state, strC.Substring(0, 1));
                    strC = strC.Substring(1);
                    break;
            }
            if (result != "") break;
        }

        WriteLine(result);
    }

    private static void ChangeState(ref State state,string chara)
    {
        switch (chara)
        {
            case "a":
                state = State.A;
                break;
            case "b":
                state = State.B;
                break;
            case "c":
                state = State.C;
                break;
        }
    }
}