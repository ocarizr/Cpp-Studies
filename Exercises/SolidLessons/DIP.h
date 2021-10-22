#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details. 
//    Details should depend on abstractions.

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser // low-level
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({ parent, Relationship::parent, child });
        relations.push_back({ child, Relationship::child, parent });
    }

    vector<Person> find_all_children_of(const string& name) override
    {
        vector<Person> result;
        for (auto& relation : relations)
        {
            auto person1 = std::get<0>(relation);
            auto rel = std::get<1>(relation);
            auto person2 = std::get<2>(relation);
            if (person1.name == name && rel == Relationship::parent)
            {
                result.push_back(person2);
            }
        }
        return result;
    }
};

struct Research // high-level
{
    Research(RelationshipBrowser& browser)
    {
        for (auto& child : browser.find_all_children_of("John"))
        {
            cout << "John has a child called " << child.name << endl;
        }
    }
};

class DIP
{
public:
    void Execute()
    {
        Person parent{ "John" };
        Person child1{ "Chris" };
        Person child2{ "Matt" };

        Relationships relationships;
        relationships.add_parent_and_child(parent, child1);
        relationships.add_parent_and_child(parent, child2);

        Research _(relationships);
    }
};

