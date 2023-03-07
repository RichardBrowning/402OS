monitor bounded buffer
{
    int items[MAX ITEMS];
    int numItems = 0;
    condition full, empty;
    void produce(int v)
    {
        while (numItems == MAX ITEMS) full.wait();
        items[numItems++] = v;
        empty.signal();
    }
    int consume()
    {
        int retVal;
        while (numItems == 0)
        empty.wait();
        retVal = items[--numItems];
        full.signal();
        return retVal;
    }
}