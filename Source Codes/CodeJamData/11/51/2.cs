using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



#region Hide
static public class Serializer
{
    static public void SerializeObject(string filename, object

objectToSerialize)
    {
        Stream stream = File.Open(filename, FileMode.Create);
        BinaryFormatter bFormatter = new BinaryFormatter();
        bFormatter.Serialize(stream, objectToSerialize);
        stream.Close();
    }

    static public object DeSerializeObject(string filename)
    {
        object objectToSerialize;
        Stream stream = File.Open(filename, FileMode.Open);
        BinaryFormatter bFormatter = new BinaryFormatter();
        objectToSerialize =
           (object)bFormatter.Deserialize(stream);
        stream.Close();
        return objectToSerialize;
    }
}

class Reader : System.IO.StreamReader
{


    public Reader(string path) : base(path) { }

    public int ReadInt()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        int r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public long ReadLong()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        long r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public char ReadChar()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        return (char)this.Read();
    }
    public string ReadWord()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        while (!this.EndOfStream && char.IsWhiteSpace((char)this.Peek()))
        {
            this.Read();
        }
        StringBuilder sb = new StringBuilder();

        while (!this.EndOfStream && !char.IsWhiteSpace((char)this.Peek()))
        {
            sb.Append((char)this.Read());
        }
        return sb.ToString();
    }
}
#endregion


class Program
{

    static void Main(string[] args)
    {
        Reader sr = new Reader("F:\\test\\in.in");
        StreamWriter sw = new StreamWriter("F:\\test\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            List<string> RR = Solution(sr);
            sw.WriteLine("Case #" + (i + 1).ToString() + ":");
            foreach (var item in RR)
            {
                sw.WriteLine(item);
            }
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }

    static double[] TX,TY,BX,BY;

    static double Area(double v, double[] X, double[] Y)
    {
        int i = 0;
        double r = 0;
        while (i < X.Length - 1 && v > X[i+1])
        {
            r += ((Y[i] + Y[i + 1]) / 2.0) * (X[i + 1] - X[i]);
            i++;
        }
        double dx = (v - X[i]) / (X[i + 1] - X[i]);
        double dy = Y[i] + (Y[i + 1] - Y[i]) * dx;
        r += ((Y[i] + dy) / 2.0) * (v - X[i]);
        return r;
    }

    static double Area(double v)
    {
        return Area(v, TX, TY) - Area(v, BX, BY);
    }

    static double Cut(double a)
    {
        double min = 0;
        double max = W;
        while (min + 1e-9 < max)
        {
            double mid = (max + min) / 2.0;
            if (Area(mid) > a)
                max = mid;
            else
                min = mid;
        }
        return min;
    }
   static  int W;
    static List<string> Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.None);
        W = int.Parse(t[0]);
        int L = int.Parse(t[1]);
        int U = int.Parse(t[2]);
        int G = int.Parse(t[3]);
        TX = new double[U];
        TY = new double[U];
        BX = new double[L];
        BY = new double[L];
        for (int i = 0; i < L; i++)
        {
            t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.None);
            BX[i] = double.Parse(t[0]);
            BY[i] = double.Parse(t[1]);
        }
        for (int i = 0; i < U; i++)
        {
            t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.None);
            TX[i] = double.Parse(t[0]);
            TY[i] = double.Parse(t[1]);
        }
        double tot = Area(W);
        List<string> res = new List<string>();
        for (int i = 1; i < G; i++)
        {
            double p = (double)i / (double)G;
            res.Add(string.Format("{0:0.0000000}",Cut(p*tot)));
        }
        return res;
    }
}
