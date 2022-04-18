#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene {
 public:
  TItleScene(IOnSceneChagedListener* impl, const Parameter& parameter);
  virtual ~TItleScene();
  void update() override;
  void draw() override;
};