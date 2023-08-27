#ifndef SAVEFILEHANDLER_H
#define SAVEFILEHANDLER_H

#include <string>

class SaveFileHandler {
public:
  SaveFileHandler();
  bool saveProgress();
  bool loadProgress();
  bool checkSaveFile();
};
#endif