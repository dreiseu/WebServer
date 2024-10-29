const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <title>Kloudtech Weather Data</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- <meta http-equiv="refresh"> -->
    <meta charset="utf-8">
    <link rel="icon" type="image/png" href="icon.png">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link
        href="https://fonts.googleapis.com/css2?family=Nunito:ital,wght@0,200..1000;1,200..1000&family=Sen:wght@400..800&display=swap"
        rel="stylesheet">
    <script src="https://kit.fontawesome.com/af2d673681.js" crossorigin="anonymous"></script>
    <!-- <script src="https://cdn.tailwindcss.com"></script> -->
    <link rel="stylesheet" href="./output.css">

</head>

<body>
    <header>

        <svg class="logo size-5 sm:size-5 md:size-8 lg:size-10" viewBox="0 0 1000 1000">
            <path fill="white"
                d="M143.74,240.62l108.36-62.6v504.11l-88.65,88.65-19.72-11.39c-28.79-16.6-46.51-47.3-46.51-80.55v-357.65c0-33.25,17.72-63.95,46.51-80.55Z" />
            <path fill="white"
                d="M753.15,181.09l-408.02,408.02V124.35l108.36-62.6c28.79-16.6,64.23-16.6,93.02,0l206.64,119.34Z" />
            <path fill="white"
                d="M902.76,321.17v357.65c0,33.25-17.72,63.95-46.51,80.55l-19.72,11.39-270.77-270.77,270.77-270.77,19.72,11.39c28.79,16.6,46.51,47.3,46.51,80.55Z" />
            <path fill="#FBD008"
                d="M753.15,818.91l-206.64,119.34c-28.79,16.6-64.23,16.6-93.02,0l-206.64-119.34,253.15-253.15,253.15,253.15Z" />

        </svg>
        <!-- <h1>Kloudtech Weather Data</h1> -->
        <h1 class="text-sm sm:text-lg md:text-2xl lg:text-3xl">Kloudtech Weather Data</h1>

    </header>
    <main>
        <div
            class="grid grid-cols-3 gap-4 text-center font-nunito size-10/12 sm:size-8/12 md:size-7/12 lg:size-6/12 leading-6">
            <!--BME Temperature-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-temperature-empty text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Temperature 1</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMETemperatureValue">0</span>
                    <!-- <sup class="units">&deg;C</sup> -->
                    <span class="units">&deg;C</span>
                </div>
            </div>

            <!--BME Humidity-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-water text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Humidity 1</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMEHumidityValue">0</span>
                    <!-- <sup class="units">%</sup> -->
                    <span class="units">%</span>
                </div>
            </div>
            <!--BME Pressure-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-arrows-to-circle text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Pressure 1</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMEPressureValue">0</span>
                    <!-- <sup class="units">mb</sup> -->
                    <span class="units">mb</span>
                </div>
            </div>

            <!--Wind Speed-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-wind text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Wind Speed</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="WindSpeedValue">0</span>
                    <span class="units">kph</span>
                </div>
            </div>

        </div>


        <section class="button-section mt-20 sm:mt-20 md:mt-30 lg:mt-32 xl:mt-36 2xl:mt-40">
            <button class="button" onclick="downloadCSV()">Download CSV</button>
            <button class="button" onclick="refreshData()">Refresh Data</button>
        </section>
        <section class="time-date-section">
            <i class="far fa-clock" style="font-size:1.0rem;color:#312c04;"></i>
            <span style="font-size:1.0rem;">Time: </span>
            <span id="time" style="font-size:1.0rem;"></span>

            <i class="far fa-calendar-alt" style="font-size:1.0rem;color:#312c04" ;></i>
            <span style="font-size:1.0rem;">Date: </span>
            <span id="date" style="font-size:1.0rem;"></span>
        </section>
    </main>
    <script>
        setInterval(function () {
            getBMETemperatureData();
            getBMEHumidityData();
            getBMEPressureData();
            getWindSpeedData();
        }, 1000);

        setInterval(function () {
            // Call a function repetatively with 1 Second interval
            Time_Date();
        }, 1000);

        // BME Temperature
        function getBMETemperatureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                document.getElementById("BMETemperatureValue").innerHTML =
                    this.responseText;
            };
            xhttp.open("GET", "readBMETemperature", true);
            xhttp.send();

        }
        // BME Humidity
        function getBMEHumidityData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BMEHumidityValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBMEHumidity", true);
            xhttp.send();
            console.log(xhttp.readyState);
        }

        // BME Pressure
        function getBMEPressureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BMEPressureValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBMEPressure", true);
            xhttp.send();
        }

        // Wind speed
        function getWindSpeedData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("WindSpeedValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readWindSpeed", true);
            xhttp.send();
        }

        // Time and Date
        function Time_Date() {
            var t = new Date();
            document.getElementById("time").innerHTML = t.toLocaleTimeString();
            var d = new Date();
            const dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
            const monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
            document.getElementById("date").innerHTML = dayNames[d.getDay()] + ", " + d.getDate() + "-" + monthNames[d.getMonth()] + "-" + d.getFullYear();
        }

        // // Download CSV file
        // function downloadCSV() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             var blob = new Blob([this.responseText], { type: 'text/csv' });
        //             var url = window.URL.createObjectURL(blob);
        //             var a = document.createElement('a');
        //             a.href = url;
        //             a.download = 'data.csv';
        //             document.body.appendChild(a);
        //             a.click();
        //             document.body.removeChild(a);
        //         }
        //     };
        //     xhttp.open("GET", "downloadCSV", true);
        //     xhttp.send();
        // }

        // Refresh Data
        function refreshData() {
            getBMETemperatureData();
            getBMEHumidityData();
            getBMEPressureData();
            getWindSpeedData();            
        }

    </script>
</body>

</html>
)=====";