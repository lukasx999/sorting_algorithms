#include <iostream>

#include "./algorithms.hxx"


void SortingAlgorithm::randomize_list() {

    m_list.clear();
    size_t item_count = m_item_count;

    while (item_count--) {
        int max = 100;
        int min = 0;
        int r   = rand() % (max + 1 - min) + min;
        m_list.push_back((float) r / 100);
    }

}



SortingAlgorithm::SortingAlgorithm(size_t item_count)
    : m_list(std::vector<float>())
    , m_item_count(item_count)
    , m_cursor(0)
{
    randomize_list();
}


Bubblesort::Bubblesort(size_t item_count)
    : SortingAlgorithm(item_count)
    , m_swapped_(false)
{}


void Bubblesort::reset() {
    m_swapped_ = true;
    m_cursor = 0;
    randomize_list();
}


bool Bubblesort::is_done() {
    return m_cursor == m_list.size()-1 && !m_swapped_;
}

void Bubblesort::next() {

    if (is_done()) {
        return;
    }

    if (m_cursor == m_list.size()-1) {
        m_cursor   = 0;
        m_swapped_ = false;
    }

    float item = m_list[m_cursor];
    float next = m_list[m_cursor+1];

    // Swap
    if (item > next) {
        m_list[m_cursor] = next;
        m_list[m_cursor+1] = item;

        m_swapped_ = true;
    }

    m_cursor++;

}
