using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

sealed class Person
{
    public int Id { get; set; }
    public int[] SportIds { get; set; }
    public int SportIndex { get; set; }

    public override string ToString()
    {
        return string.Format("Id={0}, SportIds={1}, SportIndex={2}", Id, "{" + string.Join(", ", SportIds) + "}", SportIndex);
    }
}

sealed class Sport
{
    public int Id { get; set; }
    public List<Person> Participants { get; set; }
    public bool IsHeld { get; set; }

    public override string ToString()
    {
        return string.Format("Id={0}, Participants={1}, IsHeld={2}", Id, "{" + string.Join(", ", Participants.Select(p => p.Id)) + "}", IsHeld);
    }
}

public class Program
{
    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

    X[] ReadLine<X>(Func<string, X> func)
    {
        return input.ReadLine().Split(' ').Select(func).ToArray();
    }

    void WriteLineOne(object obj)
    {
        output.WriteLine("{0}", obj);
    }

    void WriteLineMany(params object[] objects)
    {
        output.WriteLine(string.Join(" ", objects.Select(obj => obj.ToString())));
    }
    #endregion

    int n, m;
    Person[] persons;

    void Read()
    {
        var line = ReadLine(int.Parse);
        n = line[0];
        m = line[1];
        persons =
            Enumerable.Range(0, n)
            .Select(i => 
                new Person()
                {
                    Id = i,
                    SportIds = ReadLine(int.Parse).Select(s => s - 1).ToArray(),
                }
            ).ToArray();
    }

    int Solve()
    {
        var sports =
            Enumerable.Range(0, m)
            .Select(i =>
                new Sport()
                {
                    Id = i,
                    Participants = new List<Person>(),
                    IsHeld = true,
                })
            .ToArray();

        foreach (var person in persons)
        {
            sports[person.SportIds[0]].Participants.Add(person);
        }

        var min = sports.Max(s => s.Participants.Count);

        for (var r = 0; r < m - 1; r++)
        {
            var maxCount = -1;
            var maxSport = default(Sport);
            foreach (var sport in sports)
            {
                if (!sport.IsHeld) continue;
                if (sport.Participants.Count > maxCount)
                {
                    maxCount = sport.Participants.Count;
                    maxSport = sport;
                }
            }

            min = Math.Min(min, maxCount);

            foreach (var participant in maxSport.Participants)
            {
                while (true)
                {
                    participant.SportIndex++;
                    if (participant.SportIndex == m) break;
                    var sport = sports[participant.SportIds[participant.SportIndex]];
                    if (!sport.IsHeld) continue;
                    sport.Participants.Add(participant);
                    break;
                }
            }

            maxSport.IsHeld = false;
            maxSport.Participants.Clear();
        }

        return min;
    }

    public void Run()
    {
        Read();
        WriteLineOne(Solve());
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).Run();
    }
}