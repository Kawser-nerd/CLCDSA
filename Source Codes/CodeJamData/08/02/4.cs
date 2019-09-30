using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GCJ_2008
{
	public enum ScheduleResult
	{
		Unknown = 0,
		Relay,
		A,
		B,
	}

	class Schedule
	{
		public int StartTime;
		public int EndTime;
		public bool IsStartFromA;
		public ScheduleResult Result;
		public int index;
	}

	class TrainTimetable: CommonProblem
	{
		public override void ProcessCase(TextReader reader, TextWriter writer)
		{
			int turnaround;
			ParseInputLine<int>(reader, out turnaround);
			int NA, NB;
			ParseInputLine<int, int>(reader, out NA, out NB);

			SortedList<int, Schedule> order = new SortedList<int,Schedule>();

			List<Schedule> list = new List<Schedule>();

			for (int i = 0; i < NA + NB; i++) {
				string beginTime, endTime;
				ParseInputLine<string, string>(reader, out beginTime, out endTime);
				Schedule sch = new Schedule();
				sch.StartTime = (int)(TimeSpan.Parse(beginTime).TotalMinutes);
				sch.EndTime = (int)(TimeSpan.Parse(endTime).TotalMinutes) + turnaround;
				sch.IsStartFromA = i < NA;
				sch.Result = ScheduleResult.Unknown;

				list.Add(sch);
				sch.index = sch.StartTime * 1000 + i;
				order.Add(sch.index, sch);
			}

			while (order.Count > 0) {
				Schedule sch = order.Values[0];
				sch.Result = sch.IsStartFromA ? ScheduleResult.A : ScheduleResult.B;
				order.Remove(sch.index);
				Console.WriteLine("Removed: {0} {1}", order.Count, sch.index);

				//
				// find relay schedule
				Schedule next = sch;
				while (true) {
					Schedule findResult = null;
					for (int i = 0; i < order.Count; i++) {
						Schedule tmp = order.Values[i];
						if (tmp.IsStartFromA == next.IsStartFromA)
							continue;

						if (next.EndTime <= tmp.StartTime) {
							findResult = tmp;
							next = tmp;
							tmp.Result = ScheduleResult.Relay;
							break;
						}
					} 
					if (findResult != null) {
						order.Remove(findResult.index);
					} else {
						break;
					}	
				}
			}

			int retA = 0;
			int retB = 0;
			foreach (Schedule sch in list) {
				switch (sch.Result) {
					case ScheduleResult.A:
						retA++;
						break;
					case ScheduleResult.B:
						retB++;
						break;
					case ScheduleResult.Relay:
						break;
					case ScheduleResult.Unknown:
						WriteError("Unexcepted");
						break;
				}
			}

			Console.WriteLine("{0} {1}", retA, retB);
			writer.WriteLine("{0} {1}", retA, retB);
		}
	}
}
