//#include <iostream>
//#include <functional>
//#include <thread>
//#include <map>
//#include <queue>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
//class dataset
//{
//public:
//    string GUID;
//    dataset()
//    {
//
//    }
//};
//
//class task
//{
//public:
//    unsigned long int ID;
//    task(function<void(dataset)> newfunc, dataset newargs, unsigned long int newID)
//    {
//        this->thisfunctionvoid = newfunc;
//        this->args = newargs;
//        this->ID = newID;
//        this->type = 0;
//    }
//    task(function<dataset(dataset)> newfunc, dataset newargs, unsigned long int newID, int o)
//    {
//        this->thisfunctionreturn = newfunc;
//        this->args = newargs;
//        this->ID = newID;
//        this->type = 1;
//    }
//    void run()
//    {
//        switch (this->type)
//        {
//        case 0:
//            this->thisfunctionvoid(this->args);
//            this->returnsval = false;
//            break;
//        case 1:
//            this->returnval = this->thisfunctionreturn(this->args);
//            this->returnsval = true;
//        default:
//            break;
//        }
//    }
//    dataset getReturn()
//    {
//        return this->returnval;
//    }
//    bool returns()
//    {
//        return this->returnsval;
//    }
//private:
//    function<void(dataset)> thisfunctionvoid;
//    function<dataset(dataset)> thisfunctionreturn;
//    dataset args;
//    dataset returnval;
//    bool returnsval;
//    unsigned short int type;
//};
//
//class threader //reqired includes: thread, map, queue, mutex, conditionvariable
//{
//protected:
//    mutex qmtx;
//    mutex rmtx;
//    map<int, dataset> results;
//    queue<task> tasks;
//    bool end;
//private:
//    /*struct threadstuff
//    {
//        thread* thisthread;
//    };*/
//    map<int, thread*> threads;
//public:
//    static void taskRunner(threader *athis)
//    {
//        cout << "thread initialized" << endl;
//        bool running = true;
//        while(running)
//        {
//            /*unique_lock<mutex> locka(controlmtx);
//            cv.wait(locka, [&]()
//                {
//                    return (athis->end || !athis->tasks.empty());
//                });*/
//            if (athis->end)
//            {
//                return;
//            };
//            if(!athis->tasks.empty())
//            {
//                athis->qmtx.lock();
//                if (athis->tasks.empty())
//                {
//                    athis->qmtx.unlock();
//                    continue;
//                }
//                task torun = athis->tasks.front(); //aquire task
//                athis->tasks.pop(); //remove task from queue
//                athis->qmtx.unlock(); 
//                torun.run(); //execute task
//                if(torun.returns()) // if the task returns
//                {
//                    athis->rmtx.lock();
//                    athis->results[torun.ID] = torun.getReturn();//add the return to the results map with the ID as key
//                    athis->rmtx.unlock(); 
//                }
//            }
//        }
//    }/*
//    void wait_thread(threadstuff* e)
//    {
//        lock_guard<mutex> L1(e->controlmtx);
//    }
//    void resume_thread(threadstuff* e)
//    {
//        e->control.notify_all();
//    }*/
//    threader(int numofthreads)
//    {
//        this->end = false;
//        for(int x = 0; x < numofthreads; x++)
//        {
//            this->threads[x] = new thread(threader::taskRunner, this);
//        }
//    }
//    void add_task(task newtask)
//    {
//        this->qmtx.lock();
//        this->tasks.push(newtask);
//        this->qmtx.unlock();
//    }
//    void add_task(function<void(dataset)> newfunc, dataset newargs, unsigned long int newID)
//    {
//        this->qmtx.lock();
//        this->tasks.push(task(newfunc,newargs,newID));
//        this->qmtx.unlock();
//    }
//    void add_task(function<dataset(dataset)> newfunc, dataset newargs, unsigned long int newID, int o)//o is to prevent ambiguous
//    {
//        this->qmtx.lock();
//        this->tasks.push(task(newfunc,newargs,newID,o));
//        this->qmtx.unlock();
//    }
//    dataset getresults(int ID)
//    {
//        return this->results[ID];
//    }
//    ~threader()
//    {
//        this->end = true;
//        for (int x = 0; x < this->threads.size(); x++)
//        {
//            this->threads[x]->join();
//        }
//    }
//};
