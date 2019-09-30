const int maxp = 100000;
#include <pe>
char line[1000000];
vector<string> data[100][20];
int N[100];
int result[100];
int64 g_result;

void ThreadsWorker(TaskContext tc, TaskDivision td, Threads& locker, KVPersistance* kv)
{
  int64 id = tc.task_id;
  auto range = td.TaskID2Range(id);
  int64 local_result = -1;
  
  locker.lock();
    cerr << id << " begins" << endl;
    if (kv && kv->storage().count(id)) local_result = kv->storage()[id];
  locker.unlock();
  
  if (local_result != -1)
  {
    locker.lock();
      g_result += local_result;
    locker.unlock();
    return;
  }
  
  TimeRecorder tr;
  local_result = 0;
  for (int64 i = range.first; i <= range.second; ++i)
  {
    const int n = N[id];
    int ans = -1;
    const int limit = 1 << n;
    auto& them = data[i];
    //cerr << n << " " << limit << endl;
    map<string, int> old;
    for (auto& iter: them[0]) old[iter] |= 2;
    for (auto& iter: them[1]) old[iter] |= 1;
    for (int mask = 0; mask < limit; ++mask)
    {
      int dig[20];
      if ((mask & 1) != 0) continue;
      if ((mask & 2) != 2) continue;
      map<string, int> mem = old;
      for (int i = 2; i < n; ++i)
      {
        if ((mask >> i) & 1)
        {
          for (auto& iter: them[i]) mem[iter] |= 1;
        }
        else
        {
          for (auto& iter: them[i]) mem[iter] |= 2;
        }
      }
      int t = 0;
      for (auto& iter: mem)
        //if (t.second == 2) ++t;
        if (iter.second == 3) ++t;
        //dbg(t);
      if (ans == -1 || t < ans) ans = t;
    }
    ::result[id] = ans;
  }
  auto usage = tr.elapsed();
  
  locker.lock();
    cerr << id << " finishes. (" << usage.format() << ")" << endl;
    cerr << "local_result = " << local_result << endl;
    cerr << "g_result = " << g_result << endl;
    if (kv) kv->set(id, local_result);
    g_result += local_result;
  locker.unlock();
}

void ThreadsRun(int64 first, int64 last, int64 block_size, int thread_count_, const char* filename = NULL)
{
  TaskDivision td(first, last, block_size);

  KVPersistance* kv = NULL;
  if (filename)
  {
    kv = new KVPersistance(filename);
  }
  
  Threads oml;
  
  std::function<void (TaskContext)> worker([=,&oml](TaskContext tc)
    {
      ::ThreadsWorker(tc, td, oml, kv);
    }
  );
  
  set_process_priority(PRIORITY_IDLE);
  
  oml.init(&worker, thread_count_);
  for (int64 i = td.first_task_; i <= td.last_task_; ++i)
  {
    oml.wait_for_queue();
    oml.add_request((int32_t)i);
  }
  oml.wait_for_end();
  
  if (kv) delete kv;
  
  //cerr << g_result << endl;
}
int main()
{
  init_primes();
  int T; scanf("%d", &T);
  for (int id = 1; id <= T; ++id)
  {
    int n; scanf("%d", &n);
    ::N[id] = n;
    while (getchar() != '\n');
    for (int i = 0; i < n; ++i)
    {
      gets(line);
      stringstream ss(line);
      string word;
      //them[i].clear();
      while (ss>>word)
      {
        data[id][i].pb(word);
      }
    }
    
    
  }
  ThreadsRun(1, T, 1, 8);
  for (int id = 1; id <= T; ++id)
  printf("Case #%d: %d\n", id, result[id]);
  return 0;
}