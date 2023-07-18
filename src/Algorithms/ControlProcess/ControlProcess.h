/*!
	\page ControlProcessPage Формирование пороговых датчиков

 	\par Разделы
 	- \ref CP_Common

	\section CP_Common Класс ControlProcess
	В методе класса sensorInfo реализована логика изменения аналогового датчика и выставления пороговых датчиков.\n
	Этот метод вызывается регулярно. Задержка перед повторным вызовом метода указывается в configure.xml параметром overrun_delay_msec.\n
	Пример:
	\code
    <settings>
        <ControlProcess
                      overrun_delay_msec="15"
                      Sensor_AI="Test_AI"
                     Threshold_High="ThreshHi"
                     Threshold_Low="ThreshLo"
        />
    </settings>
	\endcode
*/

#ifndef ControlProcess_H_
#define ControlProcess_H_
// ------------------------------------------------------------------------------------------

#include <UniXML.h>
#include "ControlProcess_SK.h"


// ------------------------------------------------------------------------------------------
/*!	
	Реализация алгоритов формирования пороговых датчиков
	\sa \ref ControlProcessPage
*/


class ControlProcess:
	public ControlProcess_SK
{
	public:


		/*! Конструктор класса.\n
		id - идентификатор объекта ControlProcess в configure.xml \n
		node - узел к которому относится объект ControlProcess */
		ControlProcess(uniset::ObjectId id, xmlNode* node);

		//! Деструктор класса
		virtual ~ControlProcess();

		enum Timers 	//! Перечисление идентификаторов используемых таймеров
		{
			//! В данном случае таймер только один - для задержки перед повторным вызовом метода sensorInfo
			tmSensorInfo = 2,
			tmIncLevel, 
			tmDecLevel
		};
	// void setState(State* st){ ////////////////////////////////////
    //         if(state != nullptr) delete state;
    //         state = st;
    //         state->SetControlProcess(this);
    //         state->init();
    //     };

    //     void step (){
    //         state->processLogic();
    //     };

    //     void PumpFillOff(){   
            
    //         std::cout << "Насос накачки отключен" << std::endl;
    //     };
    //     void PumpFillOn(){
    //          std::cout << "Насос накачки включен" << std::endl;
             
    //     };
    //     void PumpDryOff(){
    //           std::cout << "Насос откачки отключен" << std::endl;
    //     };
    //     void PumpDryOn(){
    //           std::cout << "Насос откачки включен" << std::endl;
    //     };
    //     bool start = {false};
    //     int level = {0};


	protected:
		//! Задержка перед повторным вызовом метода sensorInfo
		int StartTimerDelay;

		//! Инкремент для изменения аналогового датчика по таймеру
		int IncrementWaterLevel;

		/*! Конструктор класса по умолчанию.\n
		Доступен только для производных классов. */
		//ControlProcess();
			// state = new PupmOnState();  ///////////////////////////////////////
            // state->SetControlProcess(this);
            // state->init();
	

		/*! Выполнение очередного шага программы.\n
		Этот метод переопределяет чисто виртуальный метод  абстрактного класса ControlProcess_SK. */
		virtual void step();

		//! Метод, реализующий логику изменения аналогового датчика и выставления пороговых датчиков
		void sensorInfo( const uniset::SensorMessage *sm ) override;

		//! Метод, реализующий обработку событий по таймеру
		void timerInfo( const uniset::TimerMessage* tm ) override;

		virtual std::string getMonitInfo() const override { return {flagStartProcess}; }
	private:

		// s ///////////////////////////////////////////////////
		bool flagStartProcess = {false};
		int isLevelHight = {0};
		int isLevelLow = {0};


};
// ------------------------------------------------------------------------------------------
#endif // ControlProcess_H_
