using System;
using System.IO;

class Program {
    static void Main() {
        Solver<B>.Solve(InputType.Small);
    }
}

#region main

public enum InputType {
    Practice,
    Small,
    Large
}

public static class Solver<T> where T : BaseProblem, new() {
    public static void Solve(InputType type) {
        T problem= new T { InputType = type };
        problem.Solve();
    }
}

public abstract class BaseProblem {

    
    private StreamWriter outfile;

    protected InputReader reader;
    
    protected abstract string solveCase();

    private InputType inputType;
    public InputType InputType {
        set {
            inputType = value;
            string input = desktop+ name + "-" + inputType.ToString().ToLower() + ".in";
           
            string output = desktop + name + "-" + inputType.ToString().ToLower() + ".out";
            reader = new InputReader(input);
            outfile = new StreamWriter(output);
        }
    }

    private readonly string desktop;
    private readonly string name;
    protected BaseProblem() {
        desktop = Environment.GetFolderPath(Environment.SpecialFolder.Desktop)+"\\"; 

        this.name = this.GetType().Name;
    }

    public void Solve() {
        int testCases = reader.RowToInt();

        for (int caseNo = 1; caseNo <= testCases; caseNo++) {
            string res=solveCase();
            outfile.WriteLine(String.Format("Case #{0}: {1}", caseNo, res));
        }

        reader.Close();
        outfile.Flush();
        outfile.Close();
    }
}

public class InputReader {
    private readonly StreamReader inputStream;

    public InputReader (string inputFile) {
        if (!File.Exists(inputFile))
            throw new FileNotFoundException(inputFile);
        inputStream = new StreamReader(inputFile);
    }

    public void Close() {
        inputStream.Close();
    }

    private string readLine() {
        string sr = inputStream.ReadLine();
        return sr;
    }

    public string RowToString() {
        return readLine();
    }

    public int RowToInt() {
        string sr = readLine();
        return int.Parse(sr);
    }

    public void RowToInt(out int i) {
        string sr = readLine();
        i= int.Parse(sr);
    }




    public int[] RowToIntArray() {
        string sr = readLine();
        string[] strings = sr.Split(' ');
        int[] res=new int[strings.Length];

        for (int i = 0; i < strings.Length; i++) {
            res[i] = int.Parse(strings[i]);
        }
        
        return res;
    }

    public string[] RowToStringArray() {
        string sr = readLine();
        string[] strings = sr.Split(' ');
        return strings;
    }

    public string[] RowToStringArray(int n) {
        string sr = readLine();
        string[] strings = sr.Split(' ');
        if (strings.Length != n)
            throw new Exception("wrong bound");
        return strings;
    }

    public int[] RowToIntArray(int n) {
        string sr = readLine();
        string[] strings = sr.Split(' ');
        if (strings.Length!=n) throw new Exception("wrong bound");
        
        int[] res=new int[n];

        for (int i = 0; i < n; i++) {
            res[i] = int.Parse(strings[i]);
        }

        return res;
    }
}

#endregion