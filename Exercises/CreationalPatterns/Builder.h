#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class HTMLElement
{
    std::string name;
    std::string content;
    std::vector<HTMLElement> elements;
    int indent_size = 4;

    HTMLElement() {}
    HTMLElement(const std::string& n, const std::string& c)
    : name(n)
    , content(c)
    {
    }

public:
    void add_nested_element(const HTMLElement& e) { elements.push_back(e); }
    void add_nested_element(const std::string& e_name,
                            const std::string& e_content)
    {
        elements.push_back(HTMLElement(e_name, e_content));
    }

    std::string str(const int indent = 0) const
    {
        std::stringstream ss;
        ss << std::string(indent_size * indent, ' ') << "<" << name << ">"
           << "\n";
        if (content.size() > 0)
        {
            ss << std::string(indent_size * (indent + 1), ' ') << content
               << "\n";
        }

        for (auto&& e : elements)
        {
            ss << e.str(indent + 1);
        }

        ss << std::string(indent_size * indent, ' ') << "</" << name << ">"
           << "\n";
        return ss.str();
    }

    friend class HTMLBuilder;
};

class HTMLBuilder
{
    HTMLElement root;

public:
    HTMLBuilder(std::string root_name)
    : root(root_name, "")
    {
    }

    HTMLBuilder& add_child(const std::string& child_name,
                           const std::string& child_content)
    {
        root.add_nested_element(child_name, child_content);
        return *this;
    }

    std::string str() const { return root.str(); }
};

void RunBuilder()
{
    HTMLBuilder builder{"ul"};
    builder.add_child("li", "hello")
        .add_child("li", "world")
        .add_child("li", "Rafael")
        .add_child("li", "Giovanna")
        .add_child("li", "Apolo")
        .add_child("li", "Luna");
    std::cout << builder.str() << std::endl;
}
