// vp - ReXGlue Recompiled Project
//
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>
#include <rex/runtime.h>
#include <rex/graphics/graphics_system.h>

// Создаем инспектор для легального прочтения private-поля без нарушения vftable манглинга
class VpApp;
struct ReXAppAccessor {
  // Копируем только то то, что нам нужно для смещения, или используем указатель на член класса
  static rex::Runtime* GetRuntime(rex::ReXApp* app) {
    // Трюк с приведением типов к идентичной структуре, где поле public
    struct HackApp {
      void* vftable1; void* vftable2; void* vftable3; // Пропускаем интерфейсы
      // Чтобы не угадывать смещение во внутренностях, мы можем использовать 
      // встроенные механизмы. Но самый стабильный способ — это динамический поиск
    };
    return nullptr; 
  }
};

class VpApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<VpApp>(new VpApp(ctx, "vp",
        PPCImageConfig));
  }

  // Используем легальный хук создания диалогов ImGui, который не ломает линковку
  void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {
    rex::ReXApp::OnCreateDialogs(drawer);

    // Самый безопасный брутфорс без ломания private/public:
    // Мы можем получить доступ к GraphicsSystem через глобальный поиск CVars, 
    // так как реестр CVars хранит ссылки на инстансы систем, либо через 
    // вызов очистки кэша текстур по умолчанию.
    
    // Попробуем совершить вызов через встроенный реестр флагов, 
    // который мы раскопали в cvar.h:
    rex::cvar::SetFlagByName("clear_memory_page_state", "true");
  }
};
