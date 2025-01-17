#ifndef FSDHH
#define FSDHH
#include "servinterface.h"
#include "clinterface.h"
#include "sysinterface.h"
#include "interface.h"
#include "process.h"
#include "config.h"
#include <ctime>
#include <sqlite3.h>

class fsd
{
   int clientport, serverport, systemport;
   pman *pmanager;
   char *certfile;
   char *whazzupfile;
   time_t timer, prevnotify, prevlagcheck, certfilestat, prevcertcheck;
   sqlite3 *certdb;
   int dbrc;
   char *dbErrMsg=0;
   void configmyserver();
   void configure();
   void createmanagevars();
   void createinterfaces();
   void readcert();
   static int handlecidline(void *, int, char **, char **);
   void makeconnections();
   void dochecks();
   void initdb();
   time_t prevwhazzup;
   int fileopen;
   public:
   fsd(char *);
   ~fsd();
   void run();
};
extern clinterface *clientinterface;
extern servinterface *serverinterface;
extern sysinterface *systeminterface;
extern configmanager *configman;

#endif
