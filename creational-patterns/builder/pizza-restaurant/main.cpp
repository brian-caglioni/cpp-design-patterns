// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.

#include <iostream>
#include <memory>
#include <vector>

struct Ingredient {
  explicit Ingredient(std::string const &name) : name{name} {};
  std::string name;
};

class Pizza {
public:
  void setDoughReady() { m_doughReady = true; }
  void setReadyToServe() { m_readyToServe = true; }

  void addIngredient(std::string const &ingredient) {
    if (m_doughReady) {
      auto newIngredient = Ingredient(ingredient);
      m_ingredients.push_back(newIngredient);
    }
  }

  void listIngredients() const {
    std::cout << "Ingredients:\n";
    for (auto const &ingredient : m_ingredients) {
      std::cout << " - " << ingredient.name << '\n';
    }
  }

private:
  bool m_doughReady = false;
  bool m_readyToServe = false;
  std::vector<Ingredient> m_ingredients{};
};

class Recipe {
public:
  void addStep(std::string const &step) { m_steps.push_back(step); }

  void listSteps() const {
    std::cout << "Steps:\n";
    for (auto const &step : m_steps) {
      std::cout << " - " << step << '\n';
    }
  }

private:
  std::vector<std::string> m_steps{};
};

class Builder {
public:
  virtual ~Builder() = default;
  virtual void rollOutDough() = 0;
  virtual void addTomatoSauce() = 0;
  virtual void addMozzarella() = 0;
  virtual void addGarlic() = 0;
  virtual void bake() = 0;
};

class PizzaMaker : public Builder {
public:
  PizzaMaker() { m_pizza = std::make_unique<Pizza>(); }

  void rollOutDough() override { m_pizza->setDoughReady(); }
  void addTomatoSauce() override { m_pizza->addIngredient("Tomato Sauce"); }
  void addMozzarella() override { m_pizza->addIngredient("Mozzarella"); }
  void addGarlic() override { m_pizza->addIngredient("Garlic"); }
  void bake() override { m_pizza->setReadyToServe(); };

  std::unique_ptr<Pizza> serve() {
    auto finishedPizza = std::move(m_pizza);
    m_pizza = std::make_unique<Pizza>();
    return finishedPizza;
  }

private:
  std::unique_ptr<Pizza> m_pizza;
};

class RecipeMaker : public Builder {
public:
  RecipeMaker() { m_recipe = std::make_unique<Recipe>(); }

  void rollOutDough() override { m_recipe->addStep("Roll out the dough."); }
  void addTomatoSauce() override { m_recipe->addStep("Add Tomato Sauce."); }
  void addMozzarella() override { m_recipe->addStep("Add Mozzarella."); }
  void addGarlic() override { m_recipe->addStep("Add Garlic."); }
  void bake() override { m_recipe->addStep("Bake it."); };

  std::unique_ptr<Recipe> read() {
    auto finishedRecipe = std::move(m_recipe);
    m_recipe = std::make_unique<Recipe>();
    return finishedRecipe;
  }

private:
  std::unique_ptr<Recipe> m_recipe;
};

class Chef {
public:
  void setBuilder(Builder *builder) { m_builder = builder; };

  void prepareMargherita() {
    m_builder->rollOutDough();
    m_builder->addTomatoSauce();
    m_builder->addMozzarella();
    m_builder->bake();
  }

  void prepareMarinara() {
    m_builder->rollOutDough();
    m_builder->addTomatoSauce();
    m_builder->addGarlic();
    m_builder->bake();
  }

private:
  Builder *m_builder;
};

int main(int, char **) {
  std::cout << "\n#### "
               "cpp-design-patterns/creational-patterns/builder/"
               "pizza-restaurant/main.cpp ####\n\n";

  Chef chef;

  // Pizza

  auto pizzaMaker = std::make_unique<PizzaMaker>();
  chef.setBuilder(pizzaMaker.get());

  chef.prepareMargherita();

  auto margherita = pizzaMaker->serve();
  margherita->listIngredients();

  chef.prepareMarinara();

  auto marinara = pizzaMaker->serve();
  marinara->listIngredients();

  // Recipe

  auto recipeMaker = std::make_unique<RecipeMaker>();
  chef.setBuilder(recipeMaker.get());

  chef.prepareMargherita();

  auto margheritaRecipe = recipeMaker->read();
  margheritaRecipe->listSteps();

  std::cout << "\n#### "
               "cpp-design-patterns/creational-patterns/builder/"
               "pizza-restaurant/main.cpp ####\n\n";
  return 0;
}
