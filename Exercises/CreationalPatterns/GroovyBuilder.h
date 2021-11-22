#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

namespace GroovyBuilder
{
using namespace std;
struct Tag
{
    string name;
    string content;
    vector<Tag> children;
    vector<pair<string, string>> attributes;

    friend ostream& operator<<(ostream& os, const Tag& tag)
    {
        os << "<" << tag.name;

        for (auto&& att : tag.attributes)
        {
            os << " " << att.first << "=\"" << att.second << "\"";
        }

        if (tag.children.size() == 0 && tag.content.length() == 0)
        {
            os << "/>" << endl;
        }
        else
        {
            os << ">" << endl;

            if (tag.content.length())
            {
                os << tag.content << endl;
            }

            for (auto&& child : tag.children)
            {
                os << child;
            }

            os << "</" << tag.name << ">" << endl;
        }

        return os;
    }

protected:
    Tag(const string& name_, const string& content_)
    : name(name_)
    , content(content_)
    {
    }

    Tag(const string& name_, const vector<Tag>& children_)
    : name(name_)
    , children(children_)
    {
    }
};

struct Paragraph : public Tag
{
    Paragraph(const string& content_)
    : Tag("p", content_)
    {
    }

    Paragraph(initializer_list<Tag> children_)
    : Tag{"p", children_}
    {
    }
};

struct Image : public Tag
{
    explicit Image(const string& url)
    : Tag("img", "")
    {
        attributes.emplace_back("src", url);
    }
};
}

void RunGroovyBuilder()
{
    std::cout << GroovyBuilder::Paragraph{GroovyBuilder::Image(
                     "http://pokemon.com/pikachu.png")}
              << std::endl;
}
