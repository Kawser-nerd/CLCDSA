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
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }

    static string Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        int X = int.Parse(t[0]);
        double S = int.Parse(t[1]);
        double R = int.Parse(t[2]);
        double T = int.Parse(t[3]);
        int N = int.Parse(t[4]);
        int[] A = new int[1000001];
        int olde = 0;
        for (int i = 0; i < N; i++)
        {
            t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int B = int.Parse(t[0]);
            int E = int.Parse(t[1]);
            int w = int.Parse(t[2]);
            A[0] += B - olde;
            olde = E;
            A[w] += E - B;
        }
        A[0] += X - olde;
        double r = 0;
        for (int i = 0; i < A.Length; i++)
        {
            double l=A[i];
            double s=i;
            if (T > 0)
            {
                double g = Math.Min(l/(i+R), T);
                T -= g;
                r += g;
                l -= g * (i + R);
            }
            r += l / (i + S);
        }
        return r.ToString();
    }
}
