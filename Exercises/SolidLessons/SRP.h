#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Journal
{
    std::string title;
    std::vector<std::string> entries;

    Journal(const std::string& t)
    : title(t)
    {
    }

    void add_entry(const std::string& entry)
    {
        static int entryId = 1;
        std::stringstream ss;
        ss << entryId++ << ": " << entry;
        entries.push_back(ss.str());
    }
};

struct PersistenceManager
{
    template<typename TData>
    void save(const std::string& filename, TData& data);
};

template<>
inline void PersistenceManager::save<Journal>(const std::string& filename,
                                              Journal& data)
{
    std::fstream file(filename, std::fstream::out);

    std::stringstream serializer;
    serializer << data.title << "\n";

    for (auto&& entry : data.entries)
    {
        serializer << entry << "\n";
    }

    file << serializer.str();

    file.close();
}

class SRP
{
public:
    void Execute()
    {
        Journal journal("My Journal");

        journal.add_entry("Today I ate lasagna!");
        journal.add_entry("I am studying C++ now!");
        journal.add_entry("I bought an Xbox!");

        PersistenceManager pm;
        pm.save("MyJournal.txt", journal);
    }
};
