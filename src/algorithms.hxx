#pragma once

#include <iostream>
#include <vector>



class SortingAlgorithm {
public:

    std::vector<float> m_list;
    size_t m_item_count;
    size_t m_cursor;

    SortingAlgorithm(size_t item_count);
    virtual void next() = 0;
    virtual void reset() = 0;
    virtual bool is_done() = 0;

protected:
    void randomize_list();

};


class Bubblesort : public SortingAlgorithm {
public:

    Bubblesort(size_t item_count);
    virtual void next();
    virtual void reset();
    virtual bool is_done();

private:
    bool m_swapped_;
};
