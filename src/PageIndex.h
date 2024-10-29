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
    <style>
        *, ::before, ::after {
        --tw-border-spacing-x: 0;
        --tw-border-spacing-y: 0;
        --tw-translate-x: 0;
        --tw-translate-y: 0;
        --tw-rotate: 0;
        --tw-skew-x: 0;
        --tw-skew-y: 0;
        --tw-scale-x: 1;
        --tw-scale-y: 1;
        --tw-pan-x:  ;
        --tw-pan-y:  ;
        --tw-pinch-zoom:  ;
        --tw-scroll-snap-strictness: proximity;
        --tw-gradient-from-position:  ;
        --tw-gradient-via-position:  ;
        --tw-gradient-to-position:  ;
        --tw-ordinal:  ;
        --tw-slashed-zero:  ;
        --tw-numeric-figure:  ;
        --tw-numeric-spacing:  ;
        --tw-numeric-fraction:  ;
        --tw-ring-inset:  ;
        --tw-ring-offset-width: 0px;
        --tw-ring-offset-color: #fff;
        --tw-ring-color: rgb(59 130 246 / 0.5);
        --tw-ring-offset-shadow: 0 0 #0000;
        --tw-ring-shadow: 0 0 #0000;
        --tw-shadow: 0 0 #0000;
        --tw-shadow-colored: 0 0 #0000;
        --tw-blur:  ;
        --tw-brightness:  ;
        --tw-contrast:  ;
        --tw-grayscale:  ;
        --tw-hue-rotate:  ;
        --tw-invert:  ;
        --tw-saturate:  ;
        --tw-sepia:  ;
        --tw-drop-shadow:  ;
        --tw-backdrop-blur:  ;
        --tw-backdrop-brightness:  ;
        --tw-backdrop-contrast:  ;
        --tw-backdrop-grayscale:  ;
        --tw-backdrop-hue-rotate:  ;
        --tw-backdrop-invert:  ;
        --tw-backdrop-opacity:  ;
        --tw-backdrop-saturate:  ;
        --tw-backdrop-sepia:  ;
        --tw-contain-size:  ;
        --tw-contain-layout:  ;
        --tw-contain-paint:  ;
        --tw-contain-style:  ;
        }

        ::backdrop {
        --tw-border-spacing-x: 0;
        --tw-border-spacing-y: 0;
        --tw-translate-x: 0;
        --tw-translate-y: 0;
        --tw-rotate: 0;
        --tw-skew-x: 0;
        --tw-skew-y: 0;
        --tw-scale-x: 1;
        --tw-scale-y: 1;
        --tw-pan-x:  ;
        --tw-pan-y:  ;
        --tw-pinch-zoom:  ;
        --tw-scroll-snap-strictness: proximity;
        --tw-gradient-from-position:  ;
        --tw-gradient-via-position:  ;
        --tw-gradient-to-position:  ;
        --tw-ordinal:  ;
        --tw-slashed-zero:  ;
        --tw-numeric-figure:  ;
        --tw-numeric-spacing:  ;
        --tw-numeric-fraction:  ;
        --tw-ring-inset:  ;
        --tw-ring-offset-width: 0px;
        --tw-ring-offset-color: #fff;
        --tw-ring-color: rgb(59 130 246 / 0.5);
        --tw-ring-offset-shadow: 0 0 #0000;
        --tw-ring-shadow: 0 0 #0000;
        --tw-shadow: 0 0 #0000;
        --tw-shadow-colored: 0 0 #0000;
        --tw-blur:  ;
        --tw-brightness:  ;
        --tw-contrast:  ;
        --tw-grayscale:  ;
        --tw-hue-rotate:  ;
        --tw-invert:  ;
        --tw-saturate:  ;
        --tw-sepia:  ;
        --tw-drop-shadow:  ;
        --tw-backdrop-blur:  ;
        --tw-backdrop-brightness:  ;
        --tw-backdrop-contrast:  ;
        --tw-backdrop-grayscale:  ;
        --tw-backdrop-hue-rotate:  ;
        --tw-backdrop-invert:  ;
        --tw-backdrop-opacity:  ;
        --tw-backdrop-saturate:  ;
        --tw-backdrop-sepia:  ;
        --tw-contain-size:  ;
        --tw-contain-layout:  ;
        --tw-contain-paint:  ;
        --tw-contain-style:  ;
        }

        /*
        ! tailwindcss v3.4.14 | MIT License | https://tailwindcss.com
        */

        /*
        1. Prevent padding and border from affecting element width. (https://github.com/mozdevs/cssremedy/issues/4)
        2. Allow adding a border to an element by just adding a border-width. (https://github.com/tailwindcss/tailwindcss/pull/116)
        */

        *,
        ::before,
        ::after {
        box-sizing: border-box;
        /* 1 */
        border-width: 0;
        /* 2 */
        border-style: solid;
        /* 2 */
        border-color: #e5e7eb;
        /* 2 */
        }

        ::before,
        ::after {
        --tw-content: '';
        }

        /*
        1. Use a consistent sensible line-height in all browsers.
        2. Prevent adjustments of font size after orientation changes in iOS.
        3. Use a more readable tab size.
        4. Use the user's configured `sans` font-family by default.
        5. Use the user's configured `sans` font-feature-settings by default.
        6. Use the user's configured `sans` font-variation-settings by default.
        7. Disable tap highlights on iOS
        */

        html,
        :host {
        line-height: 1.5;
        /* 1 */
        -webkit-text-size-adjust: 100%;
        /* 2 */
        -moz-tab-size: 4;
        /* 3 */
        -o-tab-size: 4;
            tab-size: 4;
        /* 3 */
        font-family: ui-sans-serif, system-ui, sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol", "Noto Color Emoji";
        /* 4 */
        font-feature-settings: normal;
        /* 5 */
        font-variation-settings: normal;
        /* 6 */
        -webkit-tap-highlight-color: transparent;
        /* 7 */
        }

        /*
        1. Remove the margin in all browsers.
        2. Inherit line-height from `html` so users can set them as a class directly on the `html` element.
        */

        body {
        margin: 0;
        /* 1 */
        line-height: inherit;
        /* 2 */
        }

        /*
        1. Add the correct height in Firefox.
        2. Correct the inheritance of border color in Firefox. (https://bugzilla.mozilla.org/show_bug.cgi?id=190655)
        3. Ensure horizontal rules are visible by default.
        */

        hr {
        height: 0;
        /* 1 */
        color: inherit;
        /* 2 */
        border-top-width: 1px;
        /* 3 */
        }

        /*
        Add the correct text decoration in Chrome, Edge, and Safari.
        */

        abbr:where([title]) {
        -webkit-text-decoration: underline dotted;
                text-decoration: underline dotted;
        }

        /*
        Remove the default font size and weight for headings.
        */

        h1,
        h2,
        h3,
        h4,
        h5,
        h6 {
        font-size: inherit;
        font-weight: inherit;
        }

        /*
        Reset links to optimize for opt-in styling instead of opt-out.
        */

        a {
        color: inherit;
        text-decoration: inherit;
        }

        /*
        Add the correct font weight in Edge and Safari.
        */

        b,
        strong {
        font-weight: bolder;
        }

        /*
        1. Use the user's configured `mono` font-family by default.
        2. Use the user's configured `mono` font-feature-settings by default.
        3. Use the user's configured `mono` font-variation-settings by default.
        4. Correct the odd `em` font sizing in all browsers.
        */

        code,
        kbd,
        samp,
        pre {
        font-family: ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, "Liberation Mono", "Courier New", monospace;
        /* 1 */
        font-feature-settings: normal;
        /* 2 */
        font-variation-settings: normal;
        /* 3 */
        font-size: 1em;
        /* 4 */
        }

        /*
        Add the correct font size in all browsers.
        */

        small {
        font-size: 80%;
        }

        /*
        Prevent `sub` and `sup` elements from affecting the line height in all browsers.
        */

        sub,
        sup {
        font-size: 75%;
        line-height: 0;
        position: relative;
        vertical-align: baseline;
        }

        sub {
        bottom: -0.25em;
        }

        sup {
        top: -0.5em;
        }

        /*
        1. Remove text indentation from table contents in Chrome and Safari. (https://bugs.chromium.org/p/chromium/issues/detail?id=999088, https://bugs.webkit.org/show_bug.cgi?id=201297)
        2. Correct table border color inheritance in all Chrome and Safari. (https://bugs.chromium.org/p/chromium/issues/detail?id=935729, https://bugs.webkit.org/show_bug.cgi?id=195016)
        3. Remove gaps between table borders by default.
        */

        table {
        text-indent: 0;
        /* 1 */
        border-color: inherit;
        /* 2 */
        border-collapse: collapse;
        /* 3 */
        }

        /*
        1. Change the font styles in all browsers.
        2. Remove the margin in Firefox and Safari.
        3. Remove default padding in all browsers.
        */

        button,
        input,
        optgroup,
        select,
        textarea {
        font-family: inherit;
        /* 1 */
        font-feature-settings: inherit;
        /* 1 */
        font-variation-settings: inherit;
        /* 1 */
        font-size: 100%;
        /* 1 */
        font-weight: inherit;
        /* 1 */
        line-height: inherit;
        /* 1 */
        letter-spacing: inherit;
        /* 1 */
        color: inherit;
        /* 1 */
        margin: 0;
        /* 2 */
        padding: 0;
        /* 3 */
        }

        /*
        Remove the inheritance of text transform in Edge and Firefox.
        */

        button,
        select {
        text-transform: none;
        }

        /*
        1. Correct the inability to style clickable types in iOS and Safari.
        2. Remove default button styles.
        */

        button,
        input:where([type='button']),
        input:where([type='reset']),
        input:where([type='submit']) {
        -webkit-appearance: button;
        /* 1 */
        background-color: transparent;
        /* 2 */
        background-image: none;
        /* 2 */
        }

        /*
        Use the modern Firefox focus style for all focusable elements.
        */

        :-moz-focusring {
        outline: auto;
        }

        /*
        Remove the additional `:invalid` styles in Firefox. (https://github.com/mozilla/gecko-dev/blob/2f9eacd9d3d995c937b4251a5557d95d494c9be1/layout/style/res/forms.css#L728-L737)
        */

        :-moz-ui-invalid {
        box-shadow: none;
        }

        /*
        Add the correct vertical alignment in Chrome and Firefox.
        */

        progress {
        vertical-align: baseline;
        }

        /*
        Correct the cursor style of increment and decrement buttons in Safari.
        */

        ::-webkit-inner-spin-button,
        ::-webkit-outer-spin-button {
        height: auto;
        }

        /*
        1. Correct the odd appearance in Chrome and Safari.
        2. Correct the outline style in Safari.
        */

        [type='search'] {
        -webkit-appearance: textfield;
        /* 1 */
        outline-offset: -2px;
        /* 2 */
        }

        /*
        Remove the inner padding in Chrome and Safari on macOS.
        */

        ::-webkit-search-decoration {
        -webkit-appearance: none;
        }

        /*
        1. Correct the inability to style clickable types in iOS and Safari.
        2. Change font properties to `inherit` in Safari.
        */

        ::-webkit-file-upload-button {
        -webkit-appearance: button;
        /* 1 */
        font: inherit;
        /* 2 */
        }

        /*
        Add the correct display in Chrome and Safari.
        */

        summary {
        display: list-item;
        }

        /*
        Removes the default spacing and border for appropriate elements.
        */

        blockquote,
        dl,
        dd,
        h1,
        h2,
        h3,
        h4,
        h5,
        h6,
        hr,
        figure,
        p,
        pre {
        margin: 0;
        }

        fieldset {
        margin: 0;
        padding: 0;
        }

        legend {
        padding: 0;
        }

        ol,
        ul,
        menu {
        list-style: none;
        margin: 0;
        padding: 0;
        }

        /*
        Reset default styling for dialogs.
        */

        dialog {
        padding: 0;
        }

        /*
        Prevent resizing textareas horizontally by default.
        */

        textarea {
        resize: vertical;
        }

        /*
        1. Reset the default placeholder opacity in Firefox. (https://github.com/tailwindlabs/tailwindcss/issues/3300)
        2. Set the default placeholder color to the user's configured gray 400 color.
        */

        input::-moz-placeholder, textarea::-moz-placeholder {
        opacity: 1;
        /* 1 */
        color: #9ca3af;
        /* 2 */
        }

        input::placeholder,
        textarea::placeholder {
        opacity: 1;
        /* 1 */
        color: #9ca3af;
        /* 2 */
        }

        /*
        Set the default cursor for buttons.
        */

        button,
        [role="button"] {
        cursor: pointer;
        }

        /*
        Make sure disabled buttons don't get the pointer cursor.
        */

        :disabled {
        cursor: default;
        }

        /*
        1. Make replaced elements `display: block` by default. (https://github.com/mozdevs/cssremedy/issues/14)
        2. Add `vertical-align: middle` to align replaced elements more sensibly by default. (https://github.com/jensimmons/cssremedy/issues/14#issuecomment-634934210)
        This can trigger a poorly considered lint error in some tools but is included by design.
        */

        img,
        svg,
        video,
        canvas,
        audio,
        iframe,
        embed,
        object {
        display: block;
        /* 1 */
        vertical-align: middle;
        /* 2 */
        }

        /*
        Constrain images and videos to the parent width and preserve their intrinsic aspect ratio. (https://github.com/mozdevs/cssremedy/issues/14)
        */

        img,
        video {
        max-width: 100%;
        height: auto;
        }

        /* Make elements with the HTML hidden attribute stay hidden by default */

        [hidden]:where(:not([hidden="until-found"])) {
        display: none;
        }

        .absolute {
        position: absolute;
        }

        .relative {
        position: relative;
        }

        .my-2 {
        margin-top: 0.5rem;
        margin-bottom: 0.5rem;
        }

        .my-3 {
        margin-top: 0.75rem;
        margin-bottom: 0.75rem;
        }

        .mt-10 {
        margin-top: 2.5rem;
        }

        .mt-6 {
        margin-top: 1.5rem;
        }

        .mt-20 {
        margin-top: 5rem;
        }

        .mt-12 {
        margin-top: 3rem;
        }

        .mt-14 {
        margin-top: 3.5rem;
        }

        .mt-16 {
        margin-top: 4rem;
        }

        .mt-\[10\%\] {
        margin-top: 10%;
        }

        .mt-\[1\%\] {
        margin-top: 1%;
        }

        .flex {
        display: flex;
        }

        .grid {
        display: grid;
        }

        .hidden {
        display: none;
        }

        .size-10\/12 {
        width: 83.333333%;
        height: 83.333333%;
        }

        .size-5 {
        width: 1.25rem;
        height: 1.25rem;
        }

        .max-w-64 {
        max-width: 16rem;
        }

        .max-w-xs {
        max-width: 20rem;
        }

        .transform {
        transform: translate(var(--tw-translate-x), var(--tw-translate-y)) rotate(var(--tw-rotate)) skewX(var(--tw-skew-x)) skewY(var(--tw-skew-y)) scaleX(var(--tw-scale-x)) scaleY(var(--tw-scale-y));
        }

        .grid-cols-3 {
        grid-template-columns: repeat(3, minmax(0, 1fr));
        }

        .place-content-center {
        place-content: center;
        }

        .gap-4 {
        gap: 1rem;
        }

        .overflow-hidden {
        overflow: hidden;
        }

        .border {
        border-width: 1px;
        }

        .p-10 {
        padding: 2.5rem;
        }

        .text-center {
        text-align: center;
        }

        .text-sm {
        font-size: 0.875rem;
        line-height: 1.25rem;
        }

        .text-xl {
        font-size: 1.25rem;
        line-height: 1.75rem;
        }

        .text-xs {
        font-size: 0.75rem;
        line-height: 1rem;
        }

        .leading-6 {
        line-height: 1.5rem;
        }

        .transition {
        transition-property: color, background-color, border-color, text-decoration-color, fill, stroke, opacity, box-shadow, transform, filter, -webkit-backdrop-filter;
        transition-property: color, background-color, border-color, text-decoration-color, fill, stroke, opacity, box-shadow, transform, filter, backdrop-filter;
        transition-property: color, background-color, border-color, text-decoration-color, fill, stroke, opacity, box-shadow, transform, filter, backdrop-filter, -webkit-backdrop-filter;
        transition-timing-function: cubic-bezier(0.4, 0, 0.2, 1);
        transition-duration: 150ms;
        }

        @media (min-width: 640px) {
        .sm\:mt-20 {
            margin-top: 5rem;
        }

        .sm\:inline {
            display: inline;
        }

        .sm\:size-5 {
            width: 1.25rem;
            height: 1.25rem;
        }

        .sm\:size-8\/12 {
            width: 66.666667%;
            height: 66.666667%;
        }

        .sm\:text-2xl {
            font-size: 1.5rem;
            line-height: 2rem;
        }

        .sm\:text-lg {
            font-size: 1.125rem;
            line-height: 1.75rem;
        }

        .sm\:text-sm {
            font-size: 0.875rem;
            line-height: 1.25rem;
        }
        }

        @media (min-width: 768px) {
        .md\:size-7\/12 {
            width: 58.333333%;
            height: 58.333333%;
        }

        .md\:size-8 {
            width: 2rem;
            height: 2rem;
        }

        .md\:text-2xl {
            font-size: 1.5rem;
            line-height: 2rem;
        }

        .md\:text-3xl {
            font-size: 1.875rem;
            line-height: 2.25rem;
        }

        .md\:text-base {
            font-size: 1rem;
            line-height: 1.5rem;
        }
        }

        @media (min-width: 1024px) {
        .lg\:mt-40 {
            margin-top: 10rem;
        }

        .lg\:mt-36 {
            margin-top: 9rem;
        }

        .lg\:mt-32 {
            margin-top: 8rem;
        }

        .lg\:size-10 {
            width: 2.5rem;
            height: 2.5rem;
        }

        .lg\:size-6\/12 {
            width: 50%;
            height: 50%;
        }

        .lg\:text-3xl {
            font-size: 1.875rem;
            line-height: 2.25rem;
        }

        .lg\:text-4xl {
            font-size: 2.25rem;
            line-height: 2.5rem;
        }
        }

        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            animation: 1s linear infinite bgcolor;
            animation-direction: alternate;
        }

        header {
            background-color: #333;
            color: #fff;
            padding: 1em;
            text-align: center;
            display: flex;
            justify-content: center;
            align-items: center;
            position: relative;
        }

        .logo {
            height: 3rem;
            position: absolute;
            left: 1rem;
        }

        main {
            display: flex;
            flex-direction: column;
            align-items: center;
            padding: 2em;
        }

        .grid-container {
            display: grid;
            grid-template-columns: repeat(3, 1fr);
            gap: 10px;
        }

        .polygon:nth-child(3n+2) {
            transform: translateY(50%);
        }

        /* 
        .card {
            background-color: #fff;
            padding: 1em;
            border: 1px solid #ddd;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .card h2 {
            margin-top: 0;
            font-size: 1.5rem;
        } */

        .grid {
            color: #FAFDF6;
        }

        .polygon {
            display: inline-block;
            background-color: #2D2A32;
            /* 281b0dd8 2D2A32 */
            aspect-ratio: 1/cos(30deg);
            clip-path: polygon(50% -50%, 100% 50%, 50% 150%, 0 50%);
            /* height: 10em; */
            transition: color 0.25s, background-color 0.25s, scale 0.25s;
        }

        .polygon:hover,
        button:hover {
            background-color: #ffd900 !important;
            color: #2D2A32;
            scale: 1.05;
        }

        .font-nunito {
            font-family: "Nunito", sans-serif !important;
        }

        .button-section {
            margin-top: 2em;
            text-align: center;
        }

        .button {
            background-color: #333;
            color: #fff;
            border: none;
            padding: 10px 20px;
            font-size: 16px;
            cursor: pointer;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1)
        }

        .time-date-section {
            margin-top: 2em;
            text-align: center;
        }

        .units {
            font-size: 0.8em;
        }

        .down {
            background-color: red;
        }
    </style>
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
            class="grid grid-cols-3 gap-4 text-center flex font-nunito size-10/12 sm:size-8/12 md:size-7/12 lg:size-6/12 leading-6">
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
            <!--BME Temperature 2-->
            <div class="temperature max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-temperature-empty text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Temperature 2</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMETemperatureValue">0</span>
                    <span class="units">&deg;C</span>
                </div>
            </div>

            <!--BME Humidity 2-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-water text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Humidity 2</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMEHumidityValue">0</span>
                    <span class="units">%</span>
                </div>
            </div>
            <!--BME Pressure 2-->
            <div class="pressure max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-arrows-to-circle text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Pressure 2</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMEPressureValue">0</span>
                    <span class="units">mb</span>
                </div>
            </div>
            <!--BME Temperature 3-->
            <div class="temperature max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-temperature-empty text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Temperature 3</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMETemperatureValue">0</span>
                    <span class="units">&deg;C</span>
                </div>
            </div>

            <!--BME Humidity 3-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-water text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Humidity 3</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMEHumidityValue">0</span>
                    <span class="units">%</span>
                </div>
            </div>
            <!--BME Pressure 3-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-arrows-to-circle text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Pressure 3</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BMEPressureValue">0</span>
                    <span class="units">mb</span>
                </div>
            </div>
            <!--AS5600 Wind Direction-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-arrow-turn-up text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Wind Direction</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="WindDirectionValue">0</span>
                    <span class="units">&deg;</span>
                </div>
            </div>
            <!--BH1750 Light-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-lightbulb text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Light Intensity</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="LightValue">0</span>
                    <span class="units">lux</span>
                </div>
            </div>
            <!--GUVA S12SD-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-sun text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">UV Index</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="UVValue">0</span>
                </div>
            </div>
            <!--Precipitation-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-cloud-showers-heavy text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Precipitation</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="PrecipitationValue">0</span>
                    <span class="units">mm</span>
                </div>
            </div>

            <!--Gust-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-wind text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Gust</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="WindSpeedValue">0</span>
                    <span class="units">kph</span>
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


        <section class="button-section mt-20 sm:mt-20 md:mt-30 lg:mt-32 ">
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
        // setInterval(function () {
        //     getBMETemperatureData();
        //     getBMEHumidityData();
        //     getBMEPressureData();
        //     // getBMPTemperatureData();
        //     // getBMPPressureData();
        //     // getDHTHumidityData();
        //     // getWindDirectionData();
        //     // getLightData();
        //     // getUVData();
        //     // getPrecipitationData();
        //     // getWindSpeedData();
        // }, 1000);

        const noData = "No data received";

        setInterval(function () {
            // Call a function repetatively with 1 Second interval
            Time_Date();
        }, 1000);

        // BME Temperature
        function getBMETemperatureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                // if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BMETemperatureValue").innerHTML =
                        this.responseText;
                // }
                // else {
                //     temperatureClass = document.getElementsByClassName("temperature");
                //     for (var i = 0; i < temperatureClass.length; i++) {
                //         temperatureClass[i].classList.add("down")
                //     }
                //     document.getElementById("BMETemperatureValue").innerHTML = $noData;
                // }
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
        }

    </script>
</body>

</html>
)=====";