#include "keyboard.h"
#include "lib.h"

char kscan()
{
  char key = 0;           /* здесь будет храниться сам скан код клавишы */
  if (inb(0x64) & 0x01) { /* проверка нажата ли клавиша                 */
    key = inb(0x60);      /* запись скан кода клавишы                   */
  }
                          /* а вот тут и начинаются проблемы 
			   *   скан код не хранит в себе самой буквы
			   *   как сконвертировать скан код в ascii я не нашла
			   *   ниже я эксперементировала, прошу переделать говнокод
			   *   далее мой говнокод -->
			  */
  
  switch (key) {  
    case 0x10:
      return 'q';
      break;
    case 0xE:
      return '\r';
      break;
    default:
      return 0;
  }
                          /* если что то enum со скан кодами находится в keyboard.h */
}