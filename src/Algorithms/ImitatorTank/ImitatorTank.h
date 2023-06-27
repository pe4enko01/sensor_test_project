
#ifndef ImitatorTank_H_
#define ImitatorTank_H_
// ------------------------------------------------------------------------------------------

#include <UniXML.h>
#include "ImitatorTank_SK.h"
// ------------------------------------------------------------------------------------------
/*!	
	Реализация алгоритов формирования пороговых датчиков
	\sa \ref ControlProcessPage
*/
class ImitatorTank:
	public ImitatorTank_SK
{
	public:

		/*! Конструктор класса.\n
		id - идентификатор объекта ControlProcess в configure.xml \n
		node - узел к которому относится объект ControlProcess */
		ImitatorTank(uniset::ObjectId id, xmlNode* node);

		//! Деструктор класса
		virtual ~ImitatorTank();

		enum Timers 	//! Перечисление идентификаторов используемых таймеров
		{
			//! В данном случае таймер только один - для задержки перед повторным вызовом метода sensorInfo
			tmSensorInfo = 1,
			tmIncLevel, 
			tmDecLevel
		};

	protected:
		//! Задержка перед повторным вызовом метода sensorInfo
		int CheckWaterLevelTimer;

		//! Инкремент для изменения аналогового датчика по таймеру
		int IncrementWaterLevel;

		/*! Конструктор класса по умолчанию.\n
		Доступен только для производных классов. */
		ImitatorTank();

		/*! Выполнение очередного шага программы.\n
		Этот метод переопределяет чисто виртуальный метод  абстрактного класса ControlProcess_SK. */
		virtual void step(){};

		//! Метод, реализующий логику изменения аналогового датчика и выставления пороговых датчиков
		void sensorInfo( const uniset::SensorMessage *sm ) override;

		//! Метод, реализующий обработку событий по таймеру
		void timerInfo( const uniset::TimerMessage* tm ) override;
	private:

};
// ------------------------------------------------------------------------------------------
#endif // ImitatorTank_H_