#ifndef FACTORY_H
#define FACTORY_H
namespace cordite {
  namespace dm {
    class screen;
    class process;
    /*! \brief Instantiates a screen
     * Instantiates the implemented screen interface
     */
    class factory{
    public:
      static screen* createScreen();
    };
  };
};
#endif // FACTORY_H
