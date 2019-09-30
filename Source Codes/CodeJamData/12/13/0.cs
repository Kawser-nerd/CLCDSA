using System;
using System.Collections;
using System.Collections.Generic;

class Car {
	public bool left, right;
	public int s, p;
	public int index;
	public int otherlane;
	public List<Car> conflicts;
	
	public int lastverifyid = -1;
	public bool parity;
	
	public Car(int index, string[] ss) {
		this.index = index;
		left = ss[0][0] == 'L';
		right = ss[0][0] == 'R';
		s = int.Parse (ss[1]);
		p = int.Parse (ss[2]);
		otherlane = 0;
		conflicts = new List<Car>();
	}
	
	public bool verify(int checkid, bool lane) {
		if (lastverifyid == checkid) {
			return parity == lane;
		}
		
		lastverifyid = checkid;
		parity = lane;
		
		if (!lane && !left)
			return false;
		if (lane && !right)
			return false;
		
		foreach (Car c in conflicts) {
			if (!c.verify(checkid, !lane))
				return false;
		}
		return true;
	}
	
	public void addotherlane(Car other) {
		++otherlane;
		conflicts.Add(other);
	}
	
	public void init() {
		if (otherlane == 0) {
			left = true;
			right = true;
		}
		
		foreach (Car c in conflicts) {
			left &= !c.left;
			right &= !c.right;
		}
		
		if (!left && !right) {
			throw new Exception();
		}
		
//		Console.WriteLine ("init {0}: {1}:{2}", index, left, right);
	}
	
	public void rm(Car other) {
		--otherlane;
		if (otherlane == 0) {
			left = true;
			right = true;
			
			foreach (Car c in conflicts) {
				c.rmconflict(this);
			}
			
			conflicts = new List<Car>();
		}
	}
	
	public void rmconflict(Car other) {
		conflicts.Remove(other);
	}
	
	private void prop(Car other) {
		bool oldleft = left;
		bool oldright = right;
		left &= other.right;
		right &= other.left;
		
//		Console.WriteLine ("car {0}: old={1}:{2} new={3}:{4}", index, oldleft, oldright, left, right);
		
		if (!left && !right)
			throw new Exception();
		
		if (left != oldleft || right != oldright) {
			foreach (Car c in conflicts)
				c.prop(this);
		}
	}
	
	public void join(Car other) {
		++otherlane;
		if (!conflicts.Contains(other)) {
			conflicts.Add(other);
			prop(other);
		}
	}
}

class Event : IComparable<Event> {
	public Car slow, fast;
	public bool join;
	
	public Event(Car slow, Car fast, bool join) {
		this.slow = slow;
		this.fast = fast;
		this.join = join;
	}
	
	public int ds() {
		return fast.s - slow.s;
	}
	
	public int dp() {
		return slow.p - fast.p + (join ? -5 : 5);
	}
	
	public double time() {
		return 1.0 * dp () / ds ();
	}
	
	public int CompareTo(Event other) {
		int diff = this.dp() * other.ds() - other.dp() * this.ds();
		
		if (diff != 0)
			return diff;
		
		if (!this.join && other.join)
			return -1;
		if (this.join && !other.join)
			return 1;
		
		return 0;
	}
	
	static int check = 1;
	
	public bool process() {
//		Console.WriteLine ("processing event @{0} slow={1} fast={2} join={3}", time(), slow.index, fast.index, join);
		if (!join) {
			slow.rm(fast);
			fast.rm(slow);
			return true;
		} else {
			bool ok = (slow.left && fast.right) || (slow.right && fast.left);
			if (!ok)
				return false;
			
			slow.join(fast);
			fast.join(slow);
			bool v1 = slow.verify(check++, false);
			bool v2 = slow.verify(check++, true);
			return v1 || v2;
		}
	}
}

public class A {
	public string solve() {
		int n = int.Parse(Console.ReadLine ());
		Car[] cars = new Car[n];
		for (int i = 0; i < n; ++i)
			cars[i] = new Car(i, Console.ReadLine ().Split (' '));
		
		List<Event> events = new List<Event>();
		foreach (Car slow in cars)
			foreach (Car fast in cars)
		{
			if (slow.s < fast.s) {
				if (slow.p - fast.p >= 5)
				{
					events.Add(new Event(slow, fast, true));
					events.Add(new Event(slow, fast, false));
				} else if (slow.p - fast.p > -5) {
					events.Add(new Event(slow, fast, false));
					slow.addotherlane(fast);
					fast.addotherlane(slow);
				}
			} else if (slow.s == fast.s && slow.index < fast.index) {
				if (slow.p - fast.p < 5 && slow.p - fast.p > -5) {
					slow.addotherlane(fast);
					fast.addotherlane(slow);
				}
			}
		}
		
		foreach (Car car in cars)
			car.init();
		
		events.Sort ();
		
		foreach (Event ev in events) {
			if (!ev.process()) {
				return ev.time().ToString();
			}
		}
		
		return "Possible";
	}
	
	public static void Main() {
		var instance = new A();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}: {1}", i, instance.solve());
		}
	}
}
