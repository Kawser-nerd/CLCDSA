#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

struct event {
	unsigned time;
	unsigned type;
	unsigned station;
};

enum { DEPARTURE, READY };
enum { A, B };

void store_event(struct event *e, unsigned time, unsigned type, unsigned station) {
	e->time = time;
	e->type = type;
	e->station = station;
}

int comparator(const void *e1, const void *e2) {
	struct event *event1 = (struct event*) e1;
	struct event *event2 = (struct event*) e2;
	if(event1->time < event2->time) return -1;
	else if(event1->time > event2->time) return 1;
	else {
		/* READY events before DEPARTURE events */
		if(event1->type == READY && event2->type == DEPARTURE) return -1;
		else if(event1->type == DEPARTURE && event2->type == READY) return 1;
		else return 0;
	}
}

void print_event(struct event *e) {
	printf("e time: %d, type: %s, station: %c\n", e->time, (e->type==DEPARTURE?"DEPARTURE":"READY"), (e->station==A?'A':'B'));
}

int main() {
	unsigned ncases;
	scanf("%u\n", &ncases);
	for(unsigned ncase = 1; ncase <= ncases; ncase++) {
		unsigned turntime, nabtrips, nbatrips;
		scanf("%u\n", &turntime);
		scanf("%u %u\n", &nabtrips, &nbatrips);
		struct event events[2 * nabtrips + 2 * nbatrips];
		unsigned nevents = 0;
		for(int atrip = 0; atrip < nabtrips; atrip++) {
			unsigned dh, dm, ah, am;
			scanf("%u:%u %u:%u\n", &dh, &dm, &ah, &am);
			store_event(&events[nevents++], dh * 60 + dm, DEPARTURE, A);
			store_event(&events[nevents++], ah * 60 + am + turntime, READY, B);
		}
		for(int btrip = 0; btrip < nbatrips; btrip++) {
			unsigned dh, dm, ah, am;
			scanf("%u:%u %u:%u\n", &dh, &dm, &ah, &am);
			store_event(&events[nevents++], dh * 60 + dm, DEPARTURE, B);
			store_event(&events[nevents++], ah * 60 + am + turntime, READY, A);
		}
		qsort(events, nevents, sizeof(struct event), comparator);
		unsigned trains_needed[2] = { 0, 0 };
		unsigned trains_ready[2] = { 0, 0 };
		for(int nevent = 0; nevent < nevents; nevent++) {
			if(DEBUG) printf("A ready: %u, B ready: %u, A needed: %u, B needed: %u\n", trains_ready[0], trains_ready[1], trains_needed[0], trains_needed[1]);
			struct event *e = &events[nevent];
			if(DEBUG) print_event(e);
			if(e->type == READY) trains_ready[e->station]++;
			if(e->type == DEPARTURE) {
				if(trains_ready[e->station] > 0) trains_ready[e->station]--;
				else trains_needed[e->station]++;
			}
		}
		printf("Case #%u: %u %u\n", ncase, trains_needed[0], trains_needed[1]);
	}
}
