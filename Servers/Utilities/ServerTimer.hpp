#ifndef UTILITIES_SERVER_TIMER
#define UTILITIES_SERVER_TIMER

void StartTick(int clientFD, int duration,
    const function<void(int, int)>& onTick = nullptr,
    const function<void(int)>& onEnd = nullptr)
{
    {
        lock_guard<mutex> lock(SessionsMutex);
        Sessions[clientFD].Initialize();
        Sessions[clientFD].Counting.store(true);
    }

    thread([clientFD, duration, onTick, onEnd]()
        {
            for (int i = 0; i < duration; i++)
            {
                bool counting = false;
                {
                    lock_guard<mutex> lock(SessionsMutex);
                    counting = Sessions[clientFD].Counting.load();
                }

                if (!counting) break;

                if (onTick) onTick(clientFD, i);

                this_thread::sleep_for(chrono::seconds(1));
            }

            if (onEnd) onEnd(clientFD);

            {
                lock_guard<mutex> lock(SessionsMutex);
                Sessions[clientFD].Counting.store(false);
            }

        }).detach();
}

#endif
