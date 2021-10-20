import vk_api
from vk_api.longpoll import VkLongPoll, VkEventType

vk_session = vk_api.VkApi(token='9575e7c7e11c8e9869cce9d038477647600e8c2af85bbf1d7e165078b31cf4ee641cbb93abcde9bd140a0')
session_api = vk_session.get_api()
longpool = VkLongPoll(vk_session)

def write_msg(user_id, message):
    vk_session.method('messages.send', {'user_id': user_id, 'message': message, 'random_id':0})

def check(x):
    file = open('data.txt', 'r', encoding='utf-8')
    if str(x) in file.read():
        return 1
    else:
        return 0
    file.close()

for event in longpool.listen():
    if event.type == VkEventType.MESSAGE_NEW:
        if event.to_me:
            x = event.user_id
            if check(x) == 1:
                write_msg(event.user_id, "Для вас доступны функции модератора.\n "
                                         "Чтобы посмотреть доступные команды напиши 'help'")
            request = event.text

            if request == "привет":
                write_msg(event.user_id, "Здравствуй, студент! "
                                         "Для того, чтобы ознакомится с функциями бота напиши 'помощь'.")
            elif request == "помощь":
                write_msg(event.user_id, "Основные функции Vk Бота Новгу:"
                                         "1)Для просмотра домашнего задания напиши 'дз'"
                                         "2)Для просмотра списка размещенных услуг среди студентов напиши 'услуги'")
            elif request == "услуги":
                write_msg(event.user_id, "Никто еще не размещал свои услуги :-(")
            elif request == "дз":
                write_msg(event.user_id, "Нет домашнего задания для отображения")
            else:
                write_msg(event.user_id, "Не понял ваш запрос...")










